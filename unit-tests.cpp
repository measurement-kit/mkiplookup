#define MKCURL_INLINE_IMPL
#define MKDATA_INLINE_IMPL
#define MKIPLOOKUP_INLINE_IMPL
#include "mkiplookup.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("mk::iplookup::ubuntu_extract works") {
  std::string ip;

  SECTION("For IPv4") {
    std::string body = "<xml><Ip>10.0.0.1</Ip></xml>";
    REQUIRE(mk::iplookup::ubuntu_extract(std::move(body), ip));
    REQUIRE(ip == "10.0.0.1");
  }

  SECTION("For IPv6") {
    std::string body = "<xml><Ip>2a00:1450:4002:802::200</Ip></xml>";
    REQUIRE(mk::iplookup::ubuntu_extract(std::move(body), ip));
    REQUIRE(ip == "2a00:1450:4002:802::200");
  }
}
