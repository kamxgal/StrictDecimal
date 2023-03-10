/*
 * Author: Kamil Galant
 * e-mail: kamil.galant@gmail.com
 * github: https://github.com/kamxgal
 *
 * Copyright (C) 2023 Kamil Galant. All Rights Reserved.
 *
 * License
 * StrictDecimal is released under BSD-3-Clause license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *  (1) Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in
 *  the documentation and/or other materials provided with the
 *  distribution.
 *
 *  (3)The name of the author may not be used to
 *  endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
#include "../decimal.hpp"
#include "test_macros.hpp"

using namespace std;
using ranged_decimal2d_t = strict::ranged_decimal_t<int64_t, 2, -1000, 1000>;
using ranged_decimal3d_t = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>;
using ranged_decimal4d_t = strict::ranged_decimal_t<int64_t, 4, -1000, 1000>;

bool test_constructing_ranged_decimal_from_double_and_parsing_to_string()
{
    ASSERT_EQ(ranged_decimal2d_t{10.11}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.110}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.111}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.112}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.113}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.114}.to_string(), "10.11");
    ASSERT_EQ(ranged_decimal2d_t{10.115}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.116}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.117}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.118}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.119}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.120}.to_string(), "10.12");
    ASSERT_EQ(ranged_decimal2d_t{10.12}.to_string(), "10.12");
    return true;
}

bool test_constructing_ranged_decimal_from_double_with_fraction_part_around_half()
{
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999991}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999991}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999991}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999992}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999992}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999992}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999993}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999993}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999993}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999994}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999994}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999994}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999995}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999995}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999995}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999996}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999996}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999996}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999997}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999997}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999997}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999998}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999998}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999998}.to_double(), 43.5);

    ASSERT_EQ(ranged_decimal2d_t{43.4999999999999}.to_string(), "43.50");
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999999}.to_float(), 43.5f);
    ASSERT_EQ(ranged_decimal2d_t{43.4999999999999}.to_double(), 43.5);
    return true;
}

bool test_constructing_ranged_decimal_from_float_and_parsing_to_float()
{
    ASSERT_EQ(ranged_decimal2d_t{10.11}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.110}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.111}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.112}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.113}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.114}.to_float(), 10.11f);
    ASSERT_EQ(ranged_decimal2d_t{10.115}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.116}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.117}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.118}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.119}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.120}.to_float(), 10.12f);
    ASSERT_EQ(ranged_decimal2d_t{10.12}.to_float(), 10.12f);
    return true;
}

bool test_constructing_ranged_decimal_from_double_and_parsing_to_double()
{
    ASSERT_EQ(ranged_decimal2d_t{10.11}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.110}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.111}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.112}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.113}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.114}.to_double(), 10.11);
    ASSERT_EQ(ranged_decimal2d_t{10.115}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.116}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.117}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.118}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.119}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.120}.to_double(), 10.12);
    ASSERT_EQ(ranged_decimal2d_t{10.12}.to_double(), 10.12);
    return true;
}

bool test_constructing_ranged_decimal_from_integer_and_parsing()
{
    ASSERT_EQ(ranged_decimal2d_t{10}.to_double(), 10.0);
    ASSERT_EQ(ranged_decimal2d_t{10}.to_float(), 10.0f);
    ASSERT_EQ(ranged_decimal2d_t{10}.to_string(), "10.00");
    return true;
}

bool test_constructing_ranged_decimal_from_direct_constructor_and_parsing()
{
    ASSERT_EQ(ranged_decimal2d_t(10, 5).to_double(), 10.05);
    ASSERT_EQ(ranged_decimal2d_t(10, 5).to_float(), 10.05f);
    ASSERT_EQ(ranged_decimal2d_t(10, 5).to_string(), "10.05");

    ASSERT_EQ(ranged_decimal2d_t(10, 50).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 50).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 50).to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t(10, 500).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 500).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 500).to_string(), "10.50");

    //
    ASSERT_EQ(ranged_decimal2d_t(10, 49).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 49).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 49).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 490).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 490).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 490).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 491).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 491).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 491).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 492).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 492).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 492).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 493).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 493).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 493).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 494).to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t(10, 494).to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t(10, 494).to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t(10, 495).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 495).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 495).to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t(10, 496).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 496).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 496).to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t(10, 497).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 497).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 497).to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t(10, 498).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 498).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 498).to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t(10, 499).to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t(10, 499).to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t(10, 499).to_string(), "10.50");
    return true;
}

bool test_constructing_ranged_decimal_from_string_and_parsing()
{
    ASSERT_EQ(ranged_decimal2d_t("10.05").to_double(), 10.05);
    ASSERT_EQ(ranged_decimal2d_t("10.05").to_float(), 10.05f);
    ASSERT_EQ(ranged_decimal2d_t("10.05").to_string(), "10.05");

    ASSERT_EQ(ranged_decimal2d_t("10.5").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.5").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.5").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.50").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.50").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.50").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.500").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.500").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.500").to_string(), "10.50");

    //
    ASSERT_EQ(ranged_decimal2d_t("10.49").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.49").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.49").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.490").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.490").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.490").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.491").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.491").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.491").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.492").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.492").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.492").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.493").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.493").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.493").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.494").to_double(), 10.49);
    ASSERT_EQ(ranged_decimal2d_t("10.494").to_float(), 10.49f);
    ASSERT_EQ(ranged_decimal2d_t("10.494").to_string(), "10.49");

    ASSERT_EQ(ranged_decimal2d_t("10.495").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.495").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.495").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.496").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.496").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.496").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.497").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.497").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.497").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.498").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.498").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.498").to_string(), "10.50");

    ASSERT_EQ(ranged_decimal2d_t("10.499").to_double(), 10.5);
    ASSERT_EQ(ranged_decimal2d_t("10.499").to_float(), 10.5f);
    ASSERT_EQ(ranged_decimal2d_t("10.499").to_string(), "10.50");
    return true;
}

bool test_adding_two_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} + ranged_decimal2d_t{10.11};

    ASSERT_EQ(number0.to_string(), "20.22");
    ASSERT_EQ(number0.to_float(), 20.22f);
    ASSERT_EQ(number0.to_double(), 20.22);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.112} + ranged_decimal2d_t{10.116};
    ASSERT_EQ(number1.to_string(), "20.23");
    ASSERT_EQ(number1.to_float(), 20.23f);
    ASSERT_EQ(number1.to_double(), 20.23);
    return true;
}

bool test_subtracting_two_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} - ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11} - ranged_decimal2d_t{0.11};
    ranged_decimal2d_t number2 = ranged_decimal2d_t{10.116} - ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number3 = ranged_decimal2d_t{10.12} - ranged_decimal2d_t{9.11};
    ranged_decimal2d_t number4 = ranged_decimal2d_t{9.11} - ranged_decimal2d_t{10.12};
    ASSERT_EQ(number0.to_string(), "0.00");
    ASSERT_EQ(number1.to_string(), "10.00");
    ASSERT_EQ(number2.to_string(), "0.01");
    ASSERT_EQ(number3.to_string(), "1.01");
    ASSERT_EQ(number4.to_string(), "-1.01");
    return true;
}

bool test_multiplying_two_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} * ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11} * ranged_decimal2d_t{0.11};
    ranged_decimal2d_t number2 = ranged_decimal2d_t{10.116} * ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number3 = ranged_decimal2d_t{10.12} * ranged_decimal2d_t{9.11};
    ranged_decimal2d_t number4 = ranged_decimal2d_t{-9.11} * ranged_decimal2d_t{10.12};
    ranged_decimal2d_t number5 = ranged_decimal2d_t{2.01} * ranged_decimal2d_t{23.5};
    ASSERT_EQ(number0.to_string(), "102.21");
    ASSERT_EQ(number1.to_string(), "1.11");
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number3.to_string(), "92.19");
    ASSERT_EQ(number4.to_string(), "-92.19");
    ASSERT_EQ(number5.to_string(), "47.24");
    return true;
}

bool test_dividing_two_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} / ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "1.00");
    ASSERT_EQ(number0.to_double(), 1.00);
    ASSERT_EQ(number0.to_float(), 1.00f);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.1} / ranged_decimal2d_t{0.1};
    ASSERT_EQ(number1.to_string(), "101.00");
    ASSERT_EQ(number1.to_double(), 101.0);
    ASSERT_EQ(number1.to_float(), 101.0f);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{9.999} / ranged_decimal2d_t{10};  // 9.999 rounded to two decimal points is 10.0
    ASSERT_EQ(number2.to_string(), "1.00");
    ASSERT_EQ(number2.to_double(), 1.0);
    ASSERT_EQ(number2.to_float(), 1.0f);

    ranged_decimal2d_t number3 = ranged_decimal2d_t{9.99} / ranged_decimal2d_t{10};
    ASSERT_EQ(number3.to_string(), "1.00");
    ASSERT_EQ(number3.to_double(), 1.0);
    ASSERT_EQ(number3.to_float(), 1.0f);
    return true;
}

bool test_adding_ranged_decimal()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11}; number0 += ranged_decimal2d_t{10, 11};

    ASSERT_EQ(number0.to_string(), "20.22");
    ASSERT_EQ(number0.to_float(), 20.22f);
    ASSERT_EQ(number0.to_double(), 20.22);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.112}; number1 += ranged_decimal2d_t{10.116};

    ASSERT_EQ(number1.to_string(), "20.23");
    ASSERT_EQ(number1.to_float(), 20.23f);
    ASSERT_EQ(number1.to_double(), 20.23);
    return true;
}

bool test_subtracting_ranged_decimal()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11}; number0 -= ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11}; number1 -= ranged_decimal2d_t{0.11};
    ranged_decimal2d_t number2 = ranged_decimal2d_t{10.116}; number2 -= ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number3 = ranged_decimal2d_t{10.12}; number3 -= ranged_decimal2d_t{9.11};
    ranged_decimal2d_t number4 = ranged_decimal2d_t{9.11}; number4 -= ranged_decimal2d_t{10.12};

    ASSERT_EQ(number0.to_string(), "0.00");
    ASSERT_EQ(number1.to_string(), "10.00");
    ASSERT_EQ(number2.to_string(), "0.01");
    ASSERT_EQ(number3.to_string(), "1.01");
    ASSERT_EQ(number4.to_string(), "-1.01");
    return true;
}

bool test_multiplying_by_ranged_decimal()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11}; number0 *= ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11}; number1 *= ranged_decimal2d_t{0.11};
    ranged_decimal2d_t number2 = ranged_decimal2d_t{10.116}; number2 *= ranged_decimal2d_t{10.11};
    ranged_decimal2d_t number3 = ranged_decimal2d_t{10.12}; number3 *= ranged_decimal2d_t{9.11};
    ranged_decimal2d_t number4 = ranged_decimal2d_t{-9.11}; number4 *= ranged_decimal2d_t{10.12};
    ranged_decimal2d_t number5 = ranged_decimal2d_t{2.01}; number5 *= ranged_decimal2d_t{23.5};

    ASSERT_EQ(number0.to_string(), "102.21");
    ASSERT_EQ(number1.to_string(), "1.11");
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number3.to_string(), "92.19");
    ASSERT_EQ(number4.to_string(), "-92.19");
    ASSERT_EQ(number5.to_string(), "47.24");
    return true;
}

bool test_dividing_by_ranged_decimal()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11}; number0 /= ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "1.00");
    ASSERT_EQ(number0.to_double(), 1.00);
    ASSERT_EQ(number0.to_float(), 1.00f);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.1}; number1 /= ranged_decimal2d_t{0.1};
    ASSERT_EQ(number1.to_string(), "101.00");
    ASSERT_EQ(number1.to_double(), 101.0);
    ASSERT_EQ(number1.to_float(), 101.0f);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{9.999}; number2 /= ranged_decimal2d_t{10};  // 9.999 rounded to two decimal points is 10.0
    ASSERT_EQ(number2.to_string(), "1.00");
    ASSERT_EQ(number2.to_double(), 1.0);
    ASSERT_EQ(number2.to_float(), 1.0f);

    ranged_decimal2d_t number3 = ranged_decimal2d_t{9.99}; number3 /= ranged_decimal2d_t{10};
    ASSERT_EQ(number3.to_string(), "1.00");
    ASSERT_EQ(number3.to_double(), 1.0);
    ASSERT_EQ(number3.to_float(), 1.0f);

    ranged_decimal2d_t number4 = ranged_decimal2d_t{9.99}; number4 /= ranged_decimal2d_t{2};
    ASSERT_EQ(number4.to_string(), "5.00");
    ASSERT_EQ(number4.to_double(), 5.0);
    ASSERT_EQ(number4.to_float(), 5.0f);
    return true;
}

bool test_getting_integer_and_fraction_part_from_ranged_decimal()
{
    ranged_decimal2d_t number0{"10.25"};
    ASSERT_EQ(number0.integer_part(), 10);
    ASSERT_EQ(number0.fraction_part(), 25);

    ranged_decimal2d_t number1{"10.255"}; // so 10.26
    ASSERT_EQ(number1.integer_part(), 10);
    ASSERT_EQ(number1.fraction_part(), 26);

    ranged_decimal2d_t number2{"9.999"}; // so 10.00
    ASSERT_EQ(number2.integer_part(), 10);
    ASSERT_EQ(number2.fraction_part(), 0);

    ranged_decimal2d_t number3{"9.99"};
    ASSERT_EQ(number3.integer_part(), 9);
    ASSERT_EQ(number3.fraction_part(), 99);
    return true;
}

bool test_multiplying_by_ranged_decimal_with_different_precision()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{23.5}; number0 *= ranged_decimal3d_t(2.010);
    ASSERT_EQ(number0.to_string(), "47.24");
    ASSERT_EQ(number0.to_double(), 47.24);
    ASSERT_EQ(number0.to_float(), 47.24f);

    strict::ranged_decimal_t<int64_t, 8, -1000, 1000> first(0, 20000);
    strict::ranged_decimal_t<int64_t, 4, -1000, 1000> second(0, 1);
    ASSERT_EQ(first.to_string(), "0.00020000");
    ASSERT_EQ(first.to_float(), 0.0002f);
    ASSERT_EQ(first.to_double(), 0.0002);

    ASSERT_EQ(second.to_string(), "0.0001");
    ASSERT_EQ(second.to_float(), 0.0001f);
    ASSERT_EQ(second.to_double(), 0.0001);

    first *= second;
    ASSERT_EQ(first.to_string(), "0.00000002");
    ASSERT_EQ(first.to_float(), 0.00000002f);
    ASSERT_EQ(first.to_double(), 0.00000002);
    return true;
}

bool test_dividing_by_ranged_decimal_with_different_precision()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{23.5}; number0 /= ranged_decimal3d_t(2);
    ASSERT_EQ(number0.to_string(), "11.75");
    ASSERT_EQ(number0.to_double(), 11.75);
    ASSERT_EQ(number0.to_float(), 11.75f);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{9.99}; number1 /= ranged_decimal3d_t(2);
    ASSERT_EQ(number1.to_string(), "5.00");
    ASSERT_EQ(number1.to_double(), 5.0);
    ASSERT_EQ(number1.to_float(), 5.0f);

    strict::ranged_decimal_t<int64_t, 8, -100000, 100000> first(0, 20000);
    strict::ranged_decimal_t<int64_t, 4, -100000, 100000> second(10000, 0);
    ASSERT_EQ(first.to_string(), "0.00020000");
    ASSERT_EQ(first.to_float(), 0.0002f);
    ASSERT_EQ(first.to_double(), 0.0002);

    ASSERT_EQ(second.to_string(), "10000.0000");
    ASSERT_EQ(second.to_float(), 10000.0f);
    ASSERT_EQ(second.to_double(), 10000.0);

    first /= second;
    ASSERT_EQ(first.to_string(), "0.00000002");
    ASSERT_EQ(first.to_float(), 0.00000002f);
    ASSERT_EQ(first.to_double(), 0.00000002);
    return true;
}

bool test_creation_of_negative_ranged_decimal_numbers()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{"-10.11"};
    ASSERT_EQ(number1.to_string(), "-10.11");
    ASSERT_EQ(number1.to_float(), -10.11f);
    ASSERT_EQ(number1.to_double(), -10.11);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{-10, 11};
    ASSERT_EQ(number2.to_string(), "-10.11");
    ASSERT_EQ(number2.to_float(), -10.11f);
    ASSERT_EQ(number2.to_double(), -10.11);

    ranged_decimal2d_t number3 = ranged_decimal2d_t{-10.11f};
    ASSERT_EQ(number3.to_string(), "-10.11");
    ASSERT_EQ(number3.to_float(), -10.11f);
    ASSERT_EQ(number3.to_double(), -10.11);
    return true;
}

bool test_adding_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} + ranged_decimal2d_t{-5.5};

    ASSERT_EQ(number0.to_string(), "4.61");
    ASSERT_EQ(number0.to_float(), 4.61f);
    ASSERT_EQ(number0.to_double(), 4.61);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{-10.11} + ranged_decimal2d_t{5.5};
    ASSERT_EQ(number1.to_string(), "-4.61");
    ASSERT_EQ(number1.to_float(), -4.61f);
    ASSERT_EQ(number1.to_double(), -4.61);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{-10.11} + ranged_decimal2d_t{-5.5};
    ASSERT_EQ(number2.to_string(), "-15.61");
    ASSERT_EQ(number2.to_float(), -15.61f);
    ASSERT_EQ(number2.to_double(), -15.61);
    return true;
}

bool test_subtracking_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{10.11} - ranged_decimal2d_t{-5.5};

    ASSERT_EQ(number0.to_string(), "15.61");
    ASSERT_EQ(number0.to_float(), 15.61f);
    ASSERT_EQ(number0.to_double(), 15.61);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{-10.11} - ranged_decimal2d_t{5.5};
    ASSERT_EQ(number1.to_string(), "-15.61");
    ASSERT_EQ(number1.to_float(), -15.61f);
    ASSERT_EQ(number1.to_double(), -15.61);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{-10.11} - ranged_decimal2d_t{-5.5};
    ASSERT_EQ(number2.to_string(), "-4.61");
    ASSERT_EQ(number2.to_float(), -4.61f);
    ASSERT_EQ(number2.to_double(), -4.61);
    return true;
}

bool test_multiplying_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{-10.11} * ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-102.21");
    ASSERT_EQ(number0.to_float(), -102.21f);
    ASSERT_EQ(number0.to_double(), -102.21);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11} * ranged_decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "-1.11");
    ASSERT_EQ(number1.to_float(), -1.11f);
    ASSERT_EQ(number1.to_double(), -1.11);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{-10.116} * ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number2.to_float(), 102.31f);
    ASSERT_EQ(number2.to_double(), 102.31);
    return true;
}

bool test_dividing_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{-102.21} / ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{-1.11} / ranged_decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "10.09");
    ASSERT_EQ(number1.to_float(), 10.09f);
    ASSERT_EQ(number1.to_double(), 10.09);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{102.31} / ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "-10.12");
    ASSERT_EQ(number2.to_float(), -10.12f);
    ASSERT_EQ(number2.to_double(), -10.12);
    return true;
}

bool test_multiplying_by_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{-10.11}; number0 *= ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-102.21");
    ASSERT_EQ(number0.to_float(), -102.21f);
    ASSERT_EQ(number0.to_double(), -102.21);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{10.11}; number1 *= ranged_decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "-1.11");
    ASSERT_EQ(number1.to_float(), -1.11f);
    ASSERT_EQ(number1.to_double(), -1.11);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{-10.116}; number2 *= ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number2.to_float(), 102.31f);
    ASSERT_EQ(number2.to_double(), 102.31);
    return true;
}

bool test_dividing_by_negative_ranged_decimals()
{
    ranged_decimal2d_t number0 = ranged_decimal2d_t{-102.21}; number0 /= ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    ranged_decimal2d_t number1 = ranged_decimal2d_t{-1.11}; number1 /= ranged_decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "10.09");
    ASSERT_EQ(number1.to_float(), 10.09f);
    ASSERT_EQ(number1.to_double(), 10.09);

    ranged_decimal2d_t number2 = ranged_decimal2d_t{102.31}; number2 /= ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "-10.12");
    ASSERT_EQ(number2.to_float(), -10.12f);
    ASSERT_EQ(number2.to_double(), -10.12);
    return true;
}

bool test_multiplying_by_negative_ranged_decimals_with_different_precision()
{
    ranged_decimal3d_t number0 = ranged_decimal3d_t{-10.716}; number0 *= ranged_decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-108.339");
    ASSERT_EQ(number0.to_float(), -108.339f);
    ASSERT_EQ(number0.to_double(), -108.339);

    ranged_decimal3d_t number1 = ranged_decimal3d_t{10.716}; number1 *= ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number1.to_string(), "-108.339");
    ASSERT_EQ(number1.to_float(), -108.339f);
    ASSERT_EQ(number1.to_double(), -108.339);

    ranged_decimal3d_t number2 = ranged_decimal3d_t{-10.716}; number2 *= ranged_decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "108.339");
    ASSERT_EQ(number2.to_float(), 108.339f);
    ASSERT_EQ(number2.to_double(), 108.339);

    ranged_decimal2d_t number3 = ranged_decimal2d_t{-10.11}; number3 *= ranged_decimal3d_t{10.716};
    ASSERT_EQ(number3.to_string(), "-108.34");
    ASSERT_EQ(number3.to_float(), -108.34f);
    ASSERT_EQ(number3.to_double(), -108.34);

    ranged_decimal2d_t number4 = ranged_decimal2d_t{10.11}; number4 *= ranged_decimal3d_t{-10.716};
    ASSERT_EQ(number4.to_string(), "-108.34");
    ASSERT_EQ(number4.to_float(), -108.34f);
    ASSERT_EQ(number4.to_double(), -108.34);

    ranged_decimal2d_t number5 = ranged_decimal2d_t{-10.11}; number5 *= ranged_decimal3d_t{-10.716};
    ASSERT_EQ(number5.to_string(), "108.34");
    ASSERT_EQ(number5.to_float(), 108.34f);
    ASSERT_EQ(number5.to_double(), 108.34);
    return true;
}

bool test_dividing_by_negative_ranged_decimals_with_different_precision()
{
    ranged_decimal3d_t number0 = ranged_decimal3d_t{-102.525}; number0 /= ranged_decimal2d_t{10.33};
    ASSERT_EQ(number0.to_string(), "-9.925");
    ASSERT_EQ(number0.to_float(), -9.925f);
    ASSERT_EQ(number0.to_double(), -9.925);

    ranged_decimal3d_t number1 = ranged_decimal3d_t{102.525}; number1 /= ranged_decimal2d_t{-10.33};
    ASSERT_EQ(number1.to_string(), "-9.925");
    ASSERT_EQ(number1.to_float(), -9.925f);
    ASSERT_EQ(number1.to_double(), -9.925);

    ranged_decimal3d_t number2 = ranged_decimal3d_t{-102.525}; number2 /= ranged_decimal2d_t{-10.33};
    ASSERT_EQ(number2.to_string(), "9.925");
    ASSERT_EQ(number2.to_float(), 9.925f);
    ASSERT_EQ(number2.to_double(), 9.925);

    ranged_decimal2d_t number3 = ranged_decimal2d_t{-102.53}; number3 /= ranged_decimal3d_t{10.333};
    ASSERT_EQ(number3.to_string(), "-9.92");
    ASSERT_EQ(number3.to_float(), -9.92f);
    ASSERT_EQ(number3.to_double(), -9.92);

    ranged_decimal2d_t number4 = ranged_decimal2d_t{102.53}; number4 /= ranged_decimal3d_t{-10.333};
    ASSERT_EQ(number4.to_string(), "-9.92");
    ASSERT_EQ(number4.to_float(), -9.92f);
    ASSERT_EQ(number4.to_double(), -9.92);

    ranged_decimal2d_t number5 = ranged_decimal2d_t{-102.53}; number5 /= ranged_decimal3d_t{-10.333};
    ASSERT_EQ(number5.to_string(), "9.92");
    ASSERT_EQ(number5.to_float(), 9.92f);
    ASSERT_EQ(number5.to_double(), 9.92);
    return true;
}

bool test_casting_precision_down_positive_ranged_decimals()
{
    const ranged_decimal3d_t number3d = ranged_decimal3d_t{102.525};
    ASSERT_EQ(number3d.to_string(), "102.525");
    ASSERT_EQ(number3d.to_float(), 102.525f);
    ASSERT_EQ(number3d.to_double(), 102.525);

    const auto casted2d = strict::decimal_cast<int, 2>(number3d);
    ASSERT_EQ(casted2d.to_string(), "102.53");
    ASSERT_EQ(casted2d.to_float(), 102.53f);
    ASSERT_EQ(casted2d.to_double(), 102.53);

    const auto casted1d = strict::decimal_cast<int, 1>(number3d);
    ASSERT_EQ(casted1d.to_string(), "102.5");
    ASSERT_EQ(casted1d.to_float(), 102.5f);
    ASSERT_EQ(casted1d.to_double(), 102.5);
    return true;
}

bool test_casting_precision_up_positive_ranged_decimals()
{
    const ranged_decimal2d_t number2d = ranged_decimal2d_t{102.53};

    const auto casted3d = strict::decimal_cast<int, 3>(number2d);
    ASSERT_EQ(casted3d.to_string(), "102.530");
    ASSERT_EQ(casted3d.to_float(), 102.53f);
    ASSERT_EQ(casted3d.to_double(), 102.53);
    ASSERT_EQ(casted3d.integer_part(), 102);
    ASSERT_EQ(casted3d.fraction_part(), 530);

    const auto casted4d = strict::decimal_cast<int, 4>(number2d);
    ASSERT_EQ(casted4d.to_string(), "102.5300");
    ASSERT_EQ(casted4d.to_float(), 102.53f);
    ASSERT_EQ(casted4d.to_double(), 102.53);
    ASSERT_EQ(casted4d.integer_part(), 102);
    ASSERT_EQ(casted4d.fraction_part(), 5300);
    return true;
}

bool test_casting_precision_down_negative_ranged_decimals()
{
    const ranged_decimal3d_t number3d = ranged_decimal3d_t{-102.525};
    ASSERT_EQ(number3d.to_string(), "-102.525");
    ASSERT_EQ(number3d.to_float(), -102.525f);
    ASSERT_EQ(number3d.to_double(), -102.525);

    const auto casted2d = strict::decimal_cast<int, 2>(number3d);
    ASSERT_EQ(casted2d.to_string(), "-102.53");
    ASSERT_EQ(casted2d.to_float(), -102.53f);
    ASSERT_EQ(casted2d.to_double(), -102.53);

    const auto casted1d = strict::decimal_cast<int, 1>(number3d);
    ASSERT_EQ(casted1d.to_string(), "-102.5");
    ASSERT_EQ(casted1d.to_float(), -102.5f);
    ASSERT_EQ(casted1d.to_double(), -102.5);
    return true;
}

bool test_casting_precision_up_negative_ranged_decimals()
{
    const ranged_decimal2d_t number2d = ranged_decimal2d_t{-102.53};

    const auto casted3d = strict::decimal_cast<int, 3>(number2d);
    ASSERT_EQ(casted3d.to_string(), "-102.530");
    ASSERT_EQ(casted3d.to_float(), -102.53f);
    ASSERT_EQ(casted3d.to_double(), -102.53);
    ASSERT_EQ(casted3d.integer_part(), -102);
    ASSERT_EQ(casted3d.fraction_part(), 530);

    const auto casted4d = strict::decimal_cast<int, 4>(number2d);
    ASSERT_EQ(casted4d.to_string(), "-102.5300");
    ASSERT_EQ(casted4d.to_float(), -102.53f);
    ASSERT_EQ(casted4d.to_double(), -102.53);
    ASSERT_EQ(casted4d.integer_part(), -102);
    ASSERT_EQ(casted4d.fraction_part(), 5300);
    return true;
}

bool test_casting_ranged_decimal_to_different_underlying_type()
{
    const auto number2dln = strict::ranged_decimal_t<long, 2, -1000, 1000>{-102.53};
    ASSERT_EQ(number2dln.to_string(), "-102.53");
    ASSERT_EQ(number2dln.to_float(), -102.53f);
    ASSERT_EQ(number2dln.to_double(), -102.53);
    ASSERT_EQ(number2dln.integer_part(), -102);
    ASSERT_EQ(number2dln.fraction_part(), 53);

    const auto casted2din = strict::decimal_cast<int, 2>(number2dln);
    ASSERT_EQ(casted2din.to_string(), "-102.53");
    ASSERT_EQ(casted2din.to_float(), -102.53f);
    ASSERT_EQ(casted2din.to_double(), -102.53);
    ASSERT_EQ(casted2din.integer_part(), -102);
    ASSERT_EQ(casted2din.fraction_part(), 53);

    const auto number2dlp = strict::ranged_decimal_t<long, 2, -1000, 1000>{102.53};
    ASSERT_EQ(number2dlp.to_string(), "102.53");
    ASSERT_EQ(number2dlp.to_float(), 102.53f);
    ASSERT_EQ(number2dlp.to_double(), 102.53);
    ASSERT_EQ(number2dlp.integer_part(), 102);
    ASSERT_EQ(number2dlp.fraction_part(), 53);

    const auto casted2dip = strict::decimal_cast<int, 2>(number2dlp);
    ASSERT_EQ(casted2dip.to_string(), "102.53");
    ASSERT_EQ(casted2dip.to_float(), 102.53f);
    ASSERT_EQ(casted2dip.to_double(), 102.53);
    ASSERT_EQ(casted2dip.integer_part(), 102);
    ASSERT_EQ(casted2dip.fraction_part(), 53);
    return true;
}

bool test_casting_ranged_decimal_to_different_precision()
{
    const auto number2dln = strict::ranged_decimal_t<long, 2, -1000, 1000>{-102.53};
    ASSERT_EQ(number2dln.to_string(), "-102.53");
    ASSERT_EQ(number2dln.to_float(), -102.53f);
    ASSERT_EQ(number2dln.to_double(), -102.53);
    ASSERT_EQ(number2dln.integer_part(), -102);
    ASSERT_EQ(number2dln.fraction_part(), 53);

    const auto casted2din = strict::decimal_cast<long, 2>(number2dln);
    ASSERT_EQ(casted2din.to_string(), "-102.53");
    ASSERT_EQ(casted2din.to_float(), -102.53f);
    ASSERT_EQ(casted2din.to_double(), -102.53);
    ASSERT_EQ(casted2din.integer_part(), -102);
    ASSERT_EQ(casted2din.fraction_part(), 53);

    const auto number2dlp = strict::ranged_decimal_t<long, 2, -1000, 1000>{102.53};
    ASSERT_EQ(number2dlp.to_string(), "102.53");
    ASSERT_EQ(number2dlp.to_float(), 102.53f);
    ASSERT_EQ(number2dlp.to_double(), 102.53);
    ASSERT_EQ(number2dlp.integer_part(), 102);
    ASSERT_EQ(number2dlp.fraction_part(), 53);

    const auto casted2dip = strict::decimal_cast<long, 2>(number2dlp);
    ASSERT_EQ(casted2dip.to_string(), "102.53");
    ASSERT_EQ(casted2dip.to_float(), 102.53f);
    ASSERT_EQ(casted2dip.to_double(), 102.53);
    ASSERT_EQ(casted2dip.integer_part(), 102);
    ASSERT_EQ(casted2dip.fraction_part(), 53);
    return true;
}

bool test_comparing_ranged_decimals()
{
    const auto number0 = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>{"10.2346"};
    const auto number1 = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>{10.2346};
    const auto number2 = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>{10.2346f};
    const auto number3 = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>{10, 2346};

    const auto number4 = strict::ranged_decimal_t<int64_t, 3, -1000, 1000>{999, 999};

    ASSERT_EQ(number0, number1);
    ASSERT_EQ(number1, number2);
    ASSERT_EQ(number2, number3);

    ASSERT_NEQ(number0, number4);
    return true;
}

bool test_narrowing_above_max_values()
{
    const auto number0 = ranged_decimal3d_t{"99999999"};
    ASSERT_EQ(number0.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    const auto number1 = ranged_decimal3d_t{750} + ranged_decimal3d_t{750};
    ASSERT_EQ(number1.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    const auto number2 = ranged_decimal3d_t{100} * ranged_decimal3d_t{100};
    ASSERT_EQ(number2.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    auto number3 = ranged_decimal3d_t{100}; number3 *= ranged_decimal3d_t{100};
    ASSERT_EQ(number3.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    auto number4 = ranged_decimal3d_t{100}; number4 += ranged_decimal3d_t{950};
    ASSERT_EQ(number4.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    auto number5 = ranged_decimal3d_t{-100}; number5 -= ranged_decimal3d_t{950};
    ASSERT_EQ(number5.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    auto number6 = ranged_decimal3d_t{-100}; number6 *= ranged_decimal3d_t{-100};
    ASSERT_EQ(number6.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    const auto number7 = ranged_decimal3d_t{-100} * ranged_decimal3d_t{-100};
    ASSERT_EQ(number7.nominator(), ranged_decimal3d_t::NOMINATOR_MAX_VALUE);

    return true;
}

bool test_narrowing_below_min_values()
{
    const auto number0 = ranged_decimal3d_t{"-99999999"};
    ASSERT_EQ(number0.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    const auto number1 = ranged_decimal3d_t{-750} + ranged_decimal3d_t{-750};
    ASSERT_EQ(number1.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    const auto number2 = ranged_decimal3d_t{-100} * ranged_decimal3d_t{100};
    ASSERT_EQ(number2.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    auto number3 = ranged_decimal3d_t{-100}; number3 *= ranged_decimal3d_t{100};
    ASSERT_EQ(number3.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    auto number4 = ranged_decimal3d_t{-100}; number4 += ranged_decimal3d_t{-950};
    ASSERT_EQ(number4.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    auto number5 = ranged_decimal3d_t{-100}; number4 -= ranged_decimal3d_t{950};
    ASSERT_EQ(number4.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    auto number6 = ranged_decimal3d_t{-100}; number6 *= ranged_decimal3d_t{100};
    ASSERT_EQ(number6.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    const auto number7 = ranged_decimal3d_t{100} * ranged_decimal3d_t{-100};
    ASSERT_EQ(number7.nominator(), ranged_decimal3d_t::NOMINATOR_MIN_VALUE);

    return true;
}

bool test_multiplying_ranged_decimal_by_decimal()
{
    auto first = ranged_decimal4d_t{23, 5000};
    auto second = strict::decimal_t<int64_t, 2>{2, 1};

    auto first_x_second = first * second;
    auto second_x_first = second * first;

    ASSERT_EQ(first_x_second.to_string(), "47.2350");
    ASSERT_EQ(first_x_second.to_double(), 47.235);
    ASSERT_EQ(first_x_second.to_float(), 47.235f);

    ASSERT_EQ(second_x_first.to_string(), "47.24");
    ASSERT_EQ(second_x_first.to_double(), 47.24);
    ASSERT_EQ(second_x_first.to_float(), 47.24f);

    auto temp1 = first;
    temp1 *= second;
    ASSERT_EQ(temp1.to_string(), "47.2350");
    ASSERT_EQ(temp1.to_double(), 47.235);
    ASSERT_EQ(temp1.to_float(), 47.235f);

    auto temp2 = second;
    temp2 *= first;
    ASSERT_EQ(temp2.to_string(), "47.24");
    ASSERT_EQ(temp2.to_double(), 47.24);
    ASSERT_EQ(temp2.to_float(), 47.24f);
    return true;
}

bool test_handling_divide_ranged_decimal_to_positive_infinity()
{
    auto number = ranged_decimal4d_t{100};
    const auto res = number / ranged_decimal4d_t{0};
    number /= ranged_decimal4d_t{0};

    ASSERT_EQ(res.to_string(), "1000.0000");
    ASSERT_EQ(res.to_float(), 1000.0f);
    ASSERT_EQ(res.to_double(), 1000.0);

    ASSERT_EQ(number.to_string(), "1000.0000");
    ASSERT_EQ(number.to_float(), 1000.0f);
    ASSERT_EQ(number.to_double(), 1000.0);

    number = ranged_decimal4d_t{100};;
    ASSERT_EQ(number.to_string(), "100.0000");
    ASSERT_EQ(number.to_string(), "100.0000");
    ASSERT_EQ(number.to_string(), "100.0000");
    return true;
}

bool test_handling_divide_ranged_decimal_to_negative_infinity()
{
    auto number = ranged_decimal4d_t{-100};
    const auto res = number / ranged_decimal4d_t{0};
    number /= ranged_decimal4d_t{0};

    ASSERT_EQ(res.to_string(), "-1000.0000");
    ASSERT_EQ(res.to_float(), -1000.0f);
    ASSERT_EQ(res.to_double(), -1000.0);

    ASSERT_EQ(number.to_string(), "-1000.0000");
    ASSERT_EQ(number.to_float(), -1000.0f);
    ASSERT_EQ(number.to_double(), -1000.0);
    return true;
}

bool test_handling_divide_ranged_decimal_to_nan()
{
    auto number = ranged_decimal4d_t{0};
    const auto res = number / strict::decimal_t<int64_t, 2>{0};

    ASSERT_EQ(res.to_string(), "nan");
    ASSERT_TRUE(std::isnan(res.to_float()));
    ASSERT_TRUE(std::isnan(res.to_double()));

    number /= strict::ranged_decimal_t<int64_t, 2, -1, 1>{0};
    ASSERT_EQ(number.to_string(), "nan");
    ASSERT_TRUE(std::isnan(number.to_float()));
    ASSERT_TRUE(std::isnan(number.to_double()));

    number = ranged_decimal4d_t{0};
    ASSERT_EQ(number.to_string(), "0.0000");

    number /= strict::decimal_t<int64_t, 2>{0};
    ASSERT_EQ(number.to_string(), "nan");
    ASSERT_TRUE(std::isnan(number.to_float()));
    ASSERT_TRUE(std::isnan(number.to_double()));
    return true;
}
