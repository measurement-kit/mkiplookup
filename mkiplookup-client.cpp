#include <string.h>

#include <iostream>
#include <ios>

#include "mkiplookup.hpp"

#define MKDATA_INLINE_IMPL
#include "mkdata.hpp"
#define MKCURL_INLINE_IMPL
#include "mkcurl.hpp"

int main() {
  mk::iplookup::Request request;
  request.ca_bundle_path = "ca-bundle.pem";
  request.timeout = 7;
  mk::iplookup::Response response = mk::iplookup::perform(request);
  std::clog << "good: " << std::boolalpha << response.good << std::endl;
  std::clog << "bytes_sent: " << response.bytes_sent << std::endl;
  std::clog << "bytes_recv: " << response.bytes_recv << std::endl;
  std::clog << "probe_ip: " << response.probe_ip << std::endl;
  std::clog << "=== BEGIN LOGS ===" << std::endl;
  for (auto &line : response.logs) {
    std::clog << line << std::endl;
  }
  std::clog << "=== END LOGS ===" << std::endl;
}
