#include <string.h>

#include <iostream>
#include <ios>

#include "mkiplookup.h"

#define MKDATA_INLINE_IMPL
#include "mkdata.h"
#define MKCURL_INLINE_IMPL
#include "mkcurl.h"

int main() {
  mkiplookup_request_uptr request{mkiplookup_request_new_nonnull()};
  mkiplookup_request_set_ca_bundle_path(request.get(), "ca-bundle.pem");
  mkiplookup_request_set_timeout(request.get(), 7);
  mkiplookup_response_uptr response{
    mkiplookup_request_perform_nonnull(request.get())};
  std::clog << "good: " << std::boolalpha << (bool)mkiplookup_response_good(
      response.get()) << std::endl;
  std::clog << "bytes_sent: " << mkiplookup_response_get_bytes_sent(
      response.get()) << std::endl;
  std::clog << "bytes_recv: " << mkiplookup_response_get_bytes_recv(
      response.get()) << std::endl;
  std::clog << "probe_ip: " << mkiplookup_response_get_probe_ip(
      response.get()) << std::endl;
  std::clog << "=== BEGIN LOGS ===" << std::endl;
  std::clog << mkiplookup_response_moveout_logs(response);
  std::clog << "=== END LOGS ===" << std::endl;
}
