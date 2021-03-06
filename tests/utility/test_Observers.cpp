// ======================================================================== //
// Copyright 2009-2019 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#include "../catch.hpp"

#include "ospcommon/utility/Observer.h"

using namespace ospcommon::utility;

SCENARIO("Observable/Observer interfaces", "[Observers]")
{
  GIVEN("A single observable and two observers")
  {
    Observable at;

    Observer look1(at);
    Observer look2(at);

    THEN("Neither observer has been notified after construction")
    {
      REQUIRE(!look1.wasNotified());
      REQUIRE(!look2.wasNotified());
    }

    WHEN("The observable notifies")
    {
      at.notifyObservers();

      THEN("Both observers independently are notified exactly once")
      {
        REQUIRE(look1.wasNotified());
        REQUIRE(look2.wasNotified());

        REQUIRE(!look1.wasNotified());
        REQUIRE(!look2.wasNotified());
      }
    }
  }
}
