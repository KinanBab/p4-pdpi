// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "p4_pdpi/util.h"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "google/protobuf/text_format.h"
#include "google/protobuf/util/message_differencer.h"
#include "p4_pdpi/utils/testing.h"

using ::google::protobuf::util::MessageDifferencer;

namespace pdpi {

TEST(StringToIrValueTest, Okay) {
  std::vector<std::tuple<std::string, ir::Format, std::string>> testcases = {
      {"abc", ir::Format::STRING, R"pb(str: "abc")pb"},
      {"abc", ir::Format::IPV4, R"pb(ipv4: "abc")pb"},
      {"abc", ir::Format::IPV6, R"pb(ipv6: "abc")pb"},
      {"abc", ir::Format::MAC, R"pb(mac: "abc")pb"},
      {"abc", ir::Format::HEX_STRING, R"pb(hex_str: "abc")pb"},
  };
  for (const auto& [value, format, proto] : testcases) {
    ASSERT_OK_AND_ASSIGN(auto actual, FormattedStringToIrValue(value, format));
    ir::IrValue expected;
    ASSERT_OK(ReadProtoFromString(proto, &expected));
    EXPECT_TRUE(MessageDifferencer::Equals(actual, expected));
  }
}

TEST(StringToIrValueTest, InvalidFormatFails) {
  ASSERT_FALSE(FormattedStringToIrValue("abc", (ir::Format)-1).ok());
}

}  // namespace pdpi