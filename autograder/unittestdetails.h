/*
 * File: unittestdetails.h
 * -----------------------
 * This file contains declarations of a structure of details about a test
 * that is passed through the Java back-end to the autograder GUI to display.
 * 
 * @author Marty Stepp
 * @version 2016/08/01
 * - added ASSERT_DIFF_IMAGE
 * @version 2014/11/24
 * - initial version
 * @since 2014/11/24
 */

#ifndef _unittestdetails_h
#define _unittestdetails_h

#include <string>
#include "gtest.h"
#include "strlib.h"

namespace autograder {

// NOTE: must keep in sync with UNIT_TEST_TYPE_NAMES in unittestdetails.cpp
enum UnitTestType {
    TEST_ASSERT_EQUALS = 0,
    TEST_ASSERT_NOT_EQUALS,
    TEST_ASSERT_NEAR,
    TEST_ASSERT_DIFF,
    TEST_ASSERT_DIFF_IMAGE,
    TEST_ASSERT_TRUE,
    TEST_ASSERT_FALSE,
    TEST_EXCEPTION,
    TEST_NOT_EXCEPTION,
    TEST_PASS,
    TEST_FAIL,
    TEST_STYLE_CHECK,
};

struct UnitTestDetails {
public:
    UnitTestType testType;
    std::string message;
    std::string expected;
    std::string student;
    std::string valueType;
    bool passed;
    
    UnitTestDetails();
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg = "",
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    const std::string& exp,
                    const std::string& stu,
                    const std::string& vtype,
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    bool exp,
                    bool stu,
                    const std::string& vtype,
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    char exp,
                    char stu,
                    const std::string& vtype,
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    double exp,
                    double stu,
                    const std::string& vtype,
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    int exp,
                    int stu,
                    const std::string& vtype,
                    bool pass = false);
    
    UnitTestDetails(autograder::UnitTestType tp,
                    const std::string& msg,
                    const char* const exp,
                    const char* const stu,
                    const std::string& vtype,
                    bool pass = false);
    
    std::string toString() const;
};
std::ostream& operator <<(std::ostream& out, const UnitTestDetails& deets);

} // namespace autograder

#endif // _unittestdetails_h
