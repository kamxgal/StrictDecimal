/*
 * Author: Kamil Galant
 * e-mail: kamil.galant@gmail.com
 * github: https://github.com/kamxgal
 *
 * Copyright (C) 2023 Kamil Galant. All Rights Reserved.
 *
 * License
 * BigDecimal is released under BSD-3-Clause license.
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

#include <iostream>
#include <vector>

using namespace std;
using decimal2d_t = big_decimal::decimal_t<long, 2>;
using decimal3d_t = big_decimal::decimal_t<long, 3>;

#define ASSERT_EQ(a, b) if ((a) != (b)) { std::cout << "Line " << __LINE__ << ": ASSERT_EQ failed: " << a << " != " << b << std::endl; return false; }

std::vector<std::string> failed_tests;

#define EXECUTE_TEST(name) \
    std::cout << "[BEGIN]\t" << #name << std::endl; \
    if (bool res = name()) { \
        std::cout << "[SUCCESS]\t" << #name << std::endl; \
    } else { \
        std::cout << "[FAILED]\t" << #name << std::endl; \
        failed_tests.push_back(std::string(#name)); \
    }

bool test_constructing_decimal_from_double_and_parsing_to_string()
{
    ASSERT_EQ(decimal2d_t{10.11}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.110}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.111}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.112}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.113}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.114}.to_string(), "10.11");
    ASSERT_EQ(decimal2d_t{10.115}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.116}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.117}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.118}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.119}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.120}.to_string(), "10.12");
    ASSERT_EQ(decimal2d_t{10.12}.to_string(), "10.12");
    return true;
}

bool test_constructing_decimal_from_double_with_fraction_part_around_half()
{
    ASSERT_EQ(decimal2d_t{43.4999999999991}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999991}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999991}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999992}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999992}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999992}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999993}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999993}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999993}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999994}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999994}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999994}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999995}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999995}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999995}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999996}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999996}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999996}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999997}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999997}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999997}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999998}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999998}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999998}.to_double(), 43.5);

    ASSERT_EQ(decimal2d_t{43.4999999999999}.to_string(), "43.50");
    ASSERT_EQ(decimal2d_t{43.4999999999999}.to_float(), 43.5f);
    ASSERT_EQ(decimal2d_t{43.4999999999999}.to_double(), 43.5);
    return true;
}

bool test_constructing_decimal_from_float_and_parsing_to_float()
{
    ASSERT_EQ(decimal2d_t{10.11}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.110}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.111}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.112}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.113}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.114}.to_float(), 10.11f);
    ASSERT_EQ(decimal2d_t{10.115}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.116}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.117}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.118}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.119}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.120}.to_float(), 10.12f);
    ASSERT_EQ(decimal2d_t{10.12}.to_float(), 10.12f);
    return true;
}

bool test_constructing_decimal_from_double_and_parsing_to_double()
{
    ASSERT_EQ(decimal2d_t{10.11}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.110}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.111}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.112}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.113}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.114}.to_double(), 10.11);
    ASSERT_EQ(decimal2d_t{10.115}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.116}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.117}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.118}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.119}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.120}.to_double(), 10.12);
    ASSERT_EQ(decimal2d_t{10.12}.to_double(), 10.12);
    return true;
}

bool test_constructing_decimal_from_integer_and_parsing()
{
    ASSERT_EQ(decimal2d_t{10}.to_double(), 10.0);
    ASSERT_EQ(decimal2d_t{10}.to_float(), 10.0f);
    ASSERT_EQ(decimal2d_t{10}.to_string(), "10.00");
    return true;
}

bool test_constructing_decimal_from_direct_constructor_and_parsing()
{
    ASSERT_EQ(decimal2d_t(10, 5).to_double(), 10.05);
    ASSERT_EQ(decimal2d_t(10, 5).to_float(), 10.05f);
    ASSERT_EQ(decimal2d_t(10, 5).to_string(), "10.05");

    ASSERT_EQ(decimal2d_t(10, 50).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 50).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 50).to_string(), "10.50");

    ASSERT_EQ(decimal2d_t(10, 500).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 500).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 500).to_string(), "10.50");

    //
    ASSERT_EQ(decimal2d_t(10, 49).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 49).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 49).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 490).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 490).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 490).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 491).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 491).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 491).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 492).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 492).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 492).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 493).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 493).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 493).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 494).to_double(), 10.49);
    ASSERT_EQ(decimal2d_t(10, 494).to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t(10, 494).to_string(), "10.49");

    ASSERT_EQ(decimal2d_t(10, 495).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 495).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 495).to_string(), "10.50");

    ASSERT_EQ(decimal2d_t(10, 496).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 496).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 496).to_string(), "10.50");

    ASSERT_EQ(decimal2d_t(10, 497).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 497).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 497).to_string(), "10.50");

    ASSERT_EQ(decimal2d_t(10, 498).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 498).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 498).to_string(), "10.50");

    ASSERT_EQ(decimal2d_t(10, 499).to_double(), 10.5);
    ASSERT_EQ(decimal2d_t(10, 499).to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t(10, 499).to_string(), "10.50");
    return true;
}

bool test_constructing_decimal_from_string_and_parsing()
{
    ASSERT_EQ(decimal2d_t("10.05").to_double(), 10.05);
    ASSERT_EQ(decimal2d_t("10.05").to_float(), 10.05f);
    ASSERT_EQ(decimal2d_t("10.05").to_string(), "10.05");

    ASSERT_EQ(decimal2d_t("10.5").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.5").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.5").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.50").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.50").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.50").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.500").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.500").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.500").to_string(), "10.50");

    //
    ASSERT_EQ(decimal2d_t("10.49").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.49").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.49").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.490").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.490").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.490").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.491").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.491").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.491").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.492").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.492").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.492").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.493").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.493").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.493").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.494").to_double(), 10.49);
    ASSERT_EQ(decimal2d_t("10.494").to_float(), 10.49f);
    ASSERT_EQ(decimal2d_t("10.494").to_string(), "10.49");

    ASSERT_EQ(decimal2d_t("10.495").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.495").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.495").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.496").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.496").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.496").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.497").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.497").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.497").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.498").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.498").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.498").to_string(), "10.50");

    ASSERT_EQ(decimal2d_t("10.499").to_double(), 10.5);
    ASSERT_EQ(decimal2d_t("10.499").to_float(), 10.5f);
    ASSERT_EQ(decimal2d_t("10.499").to_string(), "10.50");
    return true;
}

bool test_adding_two_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} + decimal2d_t{10.11};

    ASSERT_EQ(number0.to_string(), "20.22");
    ASSERT_EQ(number0.to_float(), 20.22f);
    ASSERT_EQ(number0.to_double(), 20.22);

    decimal2d_t number1 = decimal2d_t{10.112} + decimal2d_t{10.116};
    ASSERT_EQ(number1.to_string(), "20.23");
    ASSERT_EQ(number1.to_float(), 20.23f);
    ASSERT_EQ(number1.to_double(), 20.23);
    return true;
}

bool test_subtracting_two_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} - decimal2d_t{10.11};
    decimal2d_t number1 = decimal2d_t{10.11} - decimal2d_t{0.11};
    decimal2d_t number2 = decimal2d_t{10.116} - decimal2d_t{10.11};
    decimal2d_t number3 = decimal2d_t{10.12} - decimal2d_t{9.11};
    decimal2d_t number4 = decimal2d_t{9.11} - decimal2d_t{10.12};
    ASSERT_EQ(number0.to_string(), "0.00");
    ASSERT_EQ(number1.to_string(), "10.00");
    ASSERT_EQ(number2.to_string(), "0.01");
    ASSERT_EQ(number3.to_string(), "1.01");
    ASSERT_EQ(number4.to_string(), "-1.01");
    return true;
}

bool test_multiplying_two_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} * decimal2d_t{10.11};
    decimal2d_t number1 = decimal2d_t{10.11} * decimal2d_t{0.11};
    decimal2d_t number2 = decimal2d_t{10.116} * decimal2d_t{10.11};
    decimal2d_t number3 = decimal2d_t{10.12} * decimal2d_t{9.11};
    decimal2d_t number4 = decimal2d_t{-9.11} * decimal2d_t{10.12};
    decimal2d_t number5 = decimal2d_t{2.01} * decimal2d_t{23.5};
    ASSERT_EQ(number0.to_string(), "102.21");
    ASSERT_EQ(number1.to_string(), "1.11");
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number3.to_string(), "92.19");
    ASSERT_EQ(number4.to_string(), "-92.19");
    ASSERT_EQ(number5.to_string(), "47.24");
    return true;
}

bool test_dividing_two_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} / decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "1.00");
    ASSERT_EQ(number0.to_double(), 1.00);
    ASSERT_EQ(number0.to_float(), 1.00f);

    decimal2d_t number1 = decimal2d_t{10.1} / decimal2d_t{0.1};
    ASSERT_EQ(number1.to_string(), "101.00");
    ASSERT_EQ(number1.to_double(), 101.0);
    ASSERT_EQ(number1.to_float(), 101.0f);

    decimal2d_t number2 = decimal2d_t{9.999} / decimal2d_t{10};  // 9.999 rounded to two decimal points is 10.0
    ASSERT_EQ(number2.to_string(), "1.00");
    ASSERT_EQ(number2.to_double(), 1.0);
    ASSERT_EQ(number2.to_float(), 1.0f);

    decimal2d_t number3 = decimal2d_t{9.99} / decimal2d_t{10};
    ASSERT_EQ(number3.to_string(), "1.00");
    ASSERT_EQ(number3.to_double(), 1.0);
    ASSERT_EQ(number3.to_float(), 1.0f);
    return true;
}

bool test_adding_decimal()
{
    decimal2d_t number0 = decimal2d_t{10.11}; number0 += decimal2d_t{10, 11};

    ASSERT_EQ(number0.to_string(), "20.22");
    ASSERT_EQ(number0.to_float(), 20.22f);
    ASSERT_EQ(number0.to_double(), 20.22);

    decimal2d_t number1 = decimal2d_t{10.112}; number1 += decimal2d_t{10.116};

    ASSERT_EQ(number1.to_string(), "20.23");
    ASSERT_EQ(number1.to_float(), 20.23f);
    ASSERT_EQ(number1.to_double(), 20.23);
    return true;
}

bool test_subtracting_decimal()
{
    decimal2d_t number0 = decimal2d_t{10.11}; number0 -= decimal2d_t{10.11};
    decimal2d_t number1 = decimal2d_t{10.11}; number1 -= decimal2d_t{0.11};
    decimal2d_t number2 = decimal2d_t{10.116}; number2 -= decimal2d_t{10.11};
    decimal2d_t number3 = decimal2d_t{10.12}; number3 -= decimal2d_t{9.11};
    decimal2d_t number4 = decimal2d_t{9.11}; number4 -= decimal2d_t{10.12};

    ASSERT_EQ(number0.to_string(), "0.00");
    ASSERT_EQ(number1.to_string(), "10.00");
    ASSERT_EQ(number2.to_string(), "0.01");
    ASSERT_EQ(number3.to_string(), "1.01");
    ASSERT_EQ(number4.to_string(), "-1.01");
    return true;
}

bool test_multiplying_by_decimal()
{
    decimal2d_t number0 = decimal2d_t{10.11}; number0 *= decimal2d_t{10.11};
    decimal2d_t number1 = decimal2d_t{10.11}; number1 *= decimal2d_t{0.11};
    decimal2d_t number2 = decimal2d_t{10.116}; number2 *= decimal2d_t{10.11};
    decimal2d_t number3 = decimal2d_t{10.12}; number3 *= decimal2d_t{9.11};
    decimal2d_t number4 = decimal2d_t{-9.11}; number4 *= decimal2d_t{10.12};
    decimal2d_t number5 = decimal2d_t{2.01}; number5 *= decimal2d_t{23.5};

    ASSERT_EQ(number0.to_string(), "102.21");
    ASSERT_EQ(number1.to_string(), "1.11");
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number3.to_string(), "92.19");
    ASSERT_EQ(number4.to_string(), "-92.19");
    ASSERT_EQ(number5.to_string(), "47.24");
    return true;
}

bool test_dividing_by_decimal()
{
    decimal2d_t number0 = decimal2d_t{10.11}; number0 /= decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "1.00");
    ASSERT_EQ(number0.to_double(), 1.00);
    ASSERT_EQ(number0.to_float(), 1.00f);

    decimal2d_t number1 = decimal2d_t{10.1}; number1 /= decimal2d_t{0.1};
    ASSERT_EQ(number1.to_string(), "101.00");
    ASSERT_EQ(number1.to_double(), 101.0);
    ASSERT_EQ(number1.to_float(), 101.0f);

    decimal2d_t number2 = decimal2d_t{9.999}; number2 /= decimal2d_t{10};  // 9.999 rounded to two decimal points is 10.0
    ASSERT_EQ(number2.to_string(), "1.00");
    ASSERT_EQ(number2.to_double(), 1.0);
    ASSERT_EQ(number2.to_float(), 1.0f);

    decimal2d_t number3 = decimal2d_t{9.99}; number3 /= decimal2d_t{10};
    ASSERT_EQ(number3.to_string(), "1.00");
    ASSERT_EQ(number3.to_double(), 1.0);
    ASSERT_EQ(number3.to_float(), 1.0f);

    decimal2d_t number4 = decimal2d_t{9.99}; number4 /= decimal2d_t{2};
    ASSERT_EQ(number4.to_string(), "5.00");
    ASSERT_EQ(number4.to_double(), 5.0);
    ASSERT_EQ(number4.to_float(), 5.0f);
    return true;
}

bool test_getting_integer_and_fraction_part()
{
    decimal2d_t number0{"10.25"};
    ASSERT_EQ(number0.integer_part(), 10);
    ASSERT_EQ(number0.fraction_part(), 25);

    decimal2d_t number1{"10.255"}; // so 10.26
    ASSERT_EQ(number1.integer_part(), 10);
    ASSERT_EQ(number1.fraction_part(), 26);

    decimal2d_t number2{"9.999"}; // so 10.00
    ASSERT_EQ(number2.integer_part(), 10);
    ASSERT_EQ(number2.fraction_part(), 0);

    decimal2d_t number3{"9.99"};
    ASSERT_EQ(number3.integer_part(), 9);
    ASSERT_EQ(number3.fraction_part(), 99);
    return true;
}

bool test_multiplying_by_decimal_with_different_precision()
{
    decimal2d_t number0 = decimal2d_t{23.5}; number0 *= decimal3d_t(2.010);
    ASSERT_EQ(number0.to_string(), "47.24");
    ASSERT_EQ(number0.to_double(), 47.24);
    ASSERT_EQ(number0.to_float(), 47.24f);

    big_decimal::decimal_t<int64_t, 8> first(0, 20000);
    big_decimal::decimal_t<int64_t, 4> second(0, 1);
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

bool test_dividing_by_decimal_with_different_precision()
{
    decimal2d_t number0 = decimal2d_t{23.5}; number0 /= decimal3d_t(2);
    ASSERT_EQ(number0.to_string(), "11.75");
    ASSERT_EQ(number0.to_double(), 11.75);
    ASSERT_EQ(number0.to_float(), 11.75f);

    decimal2d_t number1 = decimal2d_t{9.99}; number1 /= decimal3d_t(2);
    ASSERT_EQ(number1.to_string(), "5.00");
    ASSERT_EQ(number1.to_double(), 5.0);
    ASSERT_EQ(number1.to_float(), 5.0f);

    big_decimal::decimal_t<int64_t, 8> first(0, 20000);
    big_decimal::decimal_t<int64_t, 4> second(10000, 0);
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

bool test_creation_of_negative_numbers()
{
    decimal2d_t number0 = decimal2d_t{-10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    decimal2d_t number1 = decimal2d_t{"-10.11"};
    ASSERT_EQ(number1.to_string(), "-10.11");
    ASSERT_EQ(number1.to_float(), -10.11f);
    ASSERT_EQ(number1.to_double(), -10.11);

    decimal2d_t number2 = decimal2d_t{-10, 11};
    ASSERT_EQ(number2.to_string(), "-10.11");
    ASSERT_EQ(number2.to_float(), -10.11f);
    ASSERT_EQ(number2.to_double(), -10.11);

    decimal2d_t number3 = decimal2d_t{-10.11f};
    ASSERT_EQ(number3.to_string(), "-10.11");
    ASSERT_EQ(number3.to_float(), -10.11f);
    ASSERT_EQ(number3.to_double(), -10.11);
    return true;
}

bool test_adding_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} + decimal2d_t{-5.5};

    ASSERT_EQ(number0.to_string(), "4.61");
    ASSERT_EQ(number0.to_float(), 4.61f);
    ASSERT_EQ(number0.to_double(), 4.61);

    decimal2d_t number1 = decimal2d_t{-10.11} + decimal2d_t{5.5};
    ASSERT_EQ(number1.to_string(), "-4.61");
    ASSERT_EQ(number1.to_float(), -4.61f);
    ASSERT_EQ(number1.to_double(), -4.61);

    decimal2d_t number2 = decimal2d_t{-10.11} + decimal2d_t{-5.5};
    ASSERT_EQ(number2.to_string(), "-15.61");
    ASSERT_EQ(number2.to_float(), -15.61f);
    ASSERT_EQ(number2.to_double(), -15.61);
    return true;
}

bool test_subtracking_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{10.11} - decimal2d_t{-5.5};

    ASSERT_EQ(number0.to_string(), "15.61");
    ASSERT_EQ(number0.to_float(), 15.61f);
    ASSERT_EQ(number0.to_double(), 15.61);

    decimal2d_t number1 = decimal2d_t{-10.11} - decimal2d_t{5.5};
    ASSERT_EQ(number1.to_string(), "-15.61");
    ASSERT_EQ(number1.to_float(), -15.61f);
    ASSERT_EQ(number1.to_double(), -15.61);

    decimal2d_t number2 = decimal2d_t{-10.11} - decimal2d_t{-5.5};
    ASSERT_EQ(number2.to_string(), "-4.61");
    ASSERT_EQ(number2.to_float(), -4.61f);
    ASSERT_EQ(number2.to_double(), -4.61);
    return true;
}

bool test_multiplying_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{-10.11} * decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-102.21");
    ASSERT_EQ(number0.to_float(), -102.21f);
    ASSERT_EQ(number0.to_double(), -102.21);

    decimal2d_t number1 = decimal2d_t{10.11} * decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "-1.11");
    ASSERT_EQ(number1.to_float(), -1.11f);
    ASSERT_EQ(number1.to_double(), -1.11);

    decimal2d_t number2 = decimal2d_t{-10.116} * decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number2.to_float(), 102.31f);
    ASSERT_EQ(number2.to_double(), 102.31);
    return true;
}

bool test_dividing_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{-102.21} / decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    decimal2d_t number1 = decimal2d_t{-1.11} / decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "10.09");
    ASSERT_EQ(number1.to_float(), 10.09f);
    ASSERT_EQ(number1.to_double(), 10.09);

    decimal2d_t number2 = decimal2d_t{102.31} / decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "-10.12");
    ASSERT_EQ(number2.to_float(), -10.12f);
    ASSERT_EQ(number2.to_double(), -10.12);
    return true;
}

bool test_multiplying_by_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{-10.11}; number0 *= decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-102.21");
    ASSERT_EQ(number0.to_float(), -102.21f);
    ASSERT_EQ(number0.to_double(), -102.21);

    decimal2d_t number1 = decimal2d_t{10.11}; number1 *= decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "-1.11");
    ASSERT_EQ(number1.to_float(), -1.11f);
    ASSERT_EQ(number1.to_double(), -1.11);

    decimal2d_t number2 = decimal2d_t{-10.116}; number2 *= decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "102.31");
    ASSERT_EQ(number2.to_float(), 102.31f);
    ASSERT_EQ(number2.to_double(), 102.31);
    return true;
}

bool test_dividing_by_negative_decimals()
{
    decimal2d_t number0 = decimal2d_t{-102.21}; number0 /= decimal2d_t{10.11};
    ASSERT_EQ(number0.to_string(), "-10.11");
    ASSERT_EQ(number0.to_float(), -10.11f);
    ASSERT_EQ(number0.to_double(), -10.11);

    decimal2d_t number1 = decimal2d_t{-1.11}; number1 /= decimal2d_t{-0.11};
    ASSERT_EQ(number1.to_string(), "10.09");
    ASSERT_EQ(number1.to_float(), 10.09f);
    ASSERT_EQ(number1.to_double(), 10.09);

    decimal2d_t number2 = decimal2d_t{102.31}; number2 /= decimal2d_t{-10.11};
    ASSERT_EQ(number2.to_string(), "-10.12");
    ASSERT_EQ(number2.to_float(), -10.12f);
    ASSERT_EQ(number2.to_double(), -10.12);
    return true;
}

int main()
{
    EXECUTE_TEST(test_constructing_decimal_from_double_and_parsing_to_string);
    EXECUTE_TEST(test_constructing_decimal_from_double_with_fraction_part_around_half);
    EXECUTE_TEST(test_constructing_decimal_from_float_and_parsing_to_float);
    EXECUTE_TEST(test_constructing_decimal_from_double_and_parsing_to_double);
    EXECUTE_TEST(test_constructing_decimal_from_integer_and_parsing);
    EXECUTE_TEST(test_constructing_decimal_from_direct_constructor_and_parsing);
    EXECUTE_TEST(test_constructing_decimal_from_string_and_parsing);

    EXECUTE_TEST(test_adding_two_decimals);
    EXECUTE_TEST(test_subtracting_two_decimals);
    EXECUTE_TEST(test_multiplying_two_decimals);
    EXECUTE_TEST(test_dividing_two_decimals);

    EXECUTE_TEST(test_adding_decimal);
    EXECUTE_TEST(test_subtracting_decimal);
    EXECUTE_TEST(test_multiplying_by_decimal);
    EXECUTE_TEST(test_dividing_by_decimal);

    EXECUTE_TEST(test_getting_integer_and_fraction_part);

    EXECUTE_TEST(test_multiplying_by_decimal_with_different_precision);
    EXECUTE_TEST(test_dividing_by_decimal_with_different_precision);

    EXECUTE_TEST(test_creation_of_negative_numbers);
    EXECUTE_TEST(test_adding_negative_decimals);
    EXECUTE_TEST(test_subtracking_negative_decimals);
    EXECUTE_TEST(test_multiplying_negative_decimals);

    EXECUTE_TEST(test_multiplying_by_negative_decimals);
    EXECUTE_TEST(test_dividing_by_negative_decimals);

    for (const auto& name : failed_tests) {
        std::cerr << "[FAILED] " << name << std::endl;
    }

    return 0;
}