# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

package(
    default_visibility = ["//p4_pdpi:__subpackages__"],
)

cc_library(
    name = "pdpi",
    srcs = [
        "ir.cc",
        "pdpi.cc",
        "util.cc",
    ],
    hdrs = [
        "ir.h",
        "pdpi.h",
        "util.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":ir_cc_proto",
        "//p4_pdpi/utils:status_utils",
        "@com_github_p4lang_p4runtime//:p4info_cc_proto",
        "@com_github_p4lang_p4runtime//:p4runtime_cc_proto",
        "@com_github_p4lang_p4runtime//:p4types_cc_proto",
        "@com_google_absl//absl/algorithm:container",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
        "@com_google_absl//absl/types:variant",
    ],
)

proto_library(
    name = "ir_proto",
    srcs = ["ir.proto"],
    visibility = ["//visibility:public"],
    deps = ["@com_github_p4lang_p4runtime//:p4info_proto"],
)

cc_proto_library(
    name = "ir_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":ir_proto"],
)

cc_test(
    name = "util_test",
    srcs = ["util_test.cc"],
    deps = [
        ":pdpi",
        "//p4_pdpi/utils:testing",
        "@com_google_googletest//:gtest",
    ],
)
