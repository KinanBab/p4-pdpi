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
    default_visibility = ["//src:__subpackages__"],
)

cc_library(
    name = "status_utils",
    hdrs = [
        "status_utils.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
    ],
)

cc_library(
    name = "collections",
    hdrs = [
        "collections.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":status_utils",
        "@com_google_glog//:glog",
    ],
)

cc_library(
    name = "testing",
    hdrs = [
        "testing.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)
