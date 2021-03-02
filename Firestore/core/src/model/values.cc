/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIRESTORE_CORE_SRC_MODEL_VALUES_H_
#define FIRESTORE_CORE_SRC_MODEL_VALUES_H_

#include <string>

namespace firebase {
namespace firestore {
namespace model {

/**
 * The order of types in Firestore. This order is based on the backend's
 * ordering, but modified to support server timestamps.
 */
const int32_t TYPE_ORDER_NULL = 0;

const int32_t TYPE_ORDER_BOOLEAN = 1;
const int32_t TYPE_ORDER_NUMBER = 2;
const int32_t TYPE_ORDER_TIMESTAMP = 3;
const int32_t TYPE_ORDER_SERVER_TIMESTAMP = 4;
const int32_t TYPE_ORDER_STRING = 5;
const int32_t TYPE_ORDER_BLOB = 6;
const int32_t TYPE_ORDER_REFERENCE = 7;
const int32_t TYPE_ORDER_GEOPOINT = 8;
const int32_t TYPE_ORDER_ARRAY = 9;
const int32_t TYPE_ORDER_MAP = 10;

class Values {
 public:
  /** Returns the backend's type order of the given Value type. */
  static int32_t GetTypeOrder(const google_firestore_v1_Value& value);

  static boolean Equals(const google_firestore_v1_Value& left,
                        const google_firestore_v1_Value& right);

  static int32_t Compare(const google_firestore_v1_Value& left,
                         const google_firestore_v1_Value& right);

  /** Generate the canonical ID for the provided field value (as used in Target
   * serialization). */
  static std::string CanonicalId(const google_firestore_v1_Value& value);

 private:
  Values() = default;
};

}  // namespace model
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_SRC_MODEL_VALUES_H_
