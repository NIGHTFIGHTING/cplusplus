// Copyright (c) 2014 Baidu, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// - Access pb services via HTTP
//   ./http_client http://www.foo.com:8765/EchoService/Echo -d '{"message":"hello"}'
// - Access builtin services
//   ./http_client http://www.foo.com:8765/vars/rpc_server*
// - Access www.foo.com
//   ./http_client www.foo.com

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/channel.h>

DEFINE_string(d, "", "POST this data to the http server");
DEFINE_string(load_balancer, "rr", "The algorithm for load balancing");
DEFINE_int32(timeout_ms, 1000, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)"); 
DEFINE_string(protocol, "http", "http or h2c");

namespace brpc {
DECLARE_bool(http_verbose);
}

#if 0
class Wait : public google::protobuf::Closure { 
//class Wait { 
public:
    Wait(const brpc::CallId& call_id, const brpc::Controller& cntl) {
        _call_id = call_id;
        _cntl = cntl;
    }
    brpc::CallId _call_id;
    brpc::Controller _cntl;
public:
/*void wait_call_id(const brpc::Controller& cntl) {
        std::cout << cntl.response_attachment() << std::endl;
}*/
    void Run() {
    //    brpc::StartCancel(_rpc_id);
        std::cout << _cntl.response_attachment() << std::endl;
    }
};
#endif
//void wait_call_id(const brpc::Controller& cntl) {
/*void wait_call_id(brpc::Controller* cntl) {
        std::cout << cntl->response_attachment() << std::endl;
}*/
void HandleEchoResponse(
        brpc::Controller* cntl) {
//){
    // std::unique_ptr makes sure cntl/response will be deleted before returning.
     //std::unique_ptr<brpc::Controller> cntl_guard(cntl);
    //std::unique_ptr<example::EchoResponse> response_guard(response);

    if (cntl->Failed()) {
        LOG(WARNING) << "Fail to send EchoRequest, " << cntl->ErrorText();
        return;
    }
    LOG(INFO) << "Received response from " << cntl->remote_side()
        //<< ": " << response->message() << " (attached="
        << cntl->response_attachment() << ")"
        << " latency=" << cntl->latency_us() << "us";
}
int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    GFLAGS_NS::ParseCommandLineFlags(&argc, &argv, true);

    if (argc != 2) {
        LOG(ERROR) << "Usage: ./http_client \"http(s)://www.foo.com\"";
        return -1;
    }
    char* url = argv[1];
    
    // A Channel represents a communication line to a Server. Notice that 
    // Channel is thread-safe and can be shared by all threads in your program.
    brpc::Channel channel;
    brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.timeout_ms = FLAGS_timeout_ms/*milliseconds*/;
    options.max_retry = FLAGS_max_retry;

    // Initialize the channel, NULL means using default options. 
    // options, see `brpc/channel.h'.
    if (channel.Init(url, FLAGS_load_balancer.c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return -1;
    }

    // We will receive response synchronously, safe to put variables
    // on stack.
    brpc::Controller cntl;

    cntl.http_request().uri() = url;
    if (!FLAGS_d.empty()) {
        cntl.http_request().set_method(brpc::HTTP_METHOD_POST);
        cntl.request_attachment().append(FLAGS_d);
    }
    const brpc::CallId id1 = cntl.call_id();
    //Wait done1(id1);
    std::cout << "call_id: " << cntl.call_id() << std::endl;

    // Because `done'(last parameter) is NULL, this function waits until
    // the response comes back or error occurs(including timedout).
    //channel.CallMethod(NULL, &cntl, NULL, NULL, NULL);
    //channel.CallMethod(NULL, &cntl, NULL, NULL, google::protobuf::NewCallback(wait_call_id,
      //  cntl));
        //google::protobuf::Closure* done = brpc::NewCallback(
          //  &wait_call_id, cntl);
        google::protobuf::Closure* done = brpc::NewCallback(
            //&HandleEchoResponse, cntl, response);
            &HandleEchoResponse, &cntl);
            //&HandleEchoResponse);
    //channel.CallMethod(NULL, &cntl, NULL, NULL, &done1); 
    channel.CallMethod(NULL, &cntl, NULL, NULL, done); 
    if (cntl.Failed()) {
        std::cerr << cntl.ErrorText() << std::endl;
        return -1;
    }
    brpc::Join(id1);
    //brpc::StartCancel(id1);
    // If -http_verbose is on, brpc already prints the response to stderr.
    /*if (!brpc::FLAGS_http_verbose) {
        std::cout << cntl.response_attachment() << std::endl;
    }*/
    return 0;
}
