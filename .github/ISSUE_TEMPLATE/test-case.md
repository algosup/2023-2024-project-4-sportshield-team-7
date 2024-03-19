---
name: Test Case
about: Declares a test case.
title: "[TESTING] [TEST_ID] TEST_NAME"
labels: test
assignees: mathiskakal

---

### Test Case Title: 

*A brief title of what the test is.*
> Code Security Check

### Test Description

*Describe what the test will do in simple terms.*
> This test will read through all the code to find known vulnerability issues from a third-party database.

### Objective:

*Describe why the test is relevant.*
> The goal of this test is to ensure the product meets security requirements.

### Dependencies

*Describe the elements the test(s) depend on.*
> GCC version 12.3.0, Python version 3.11 etc.

### Preconditions:

*Any requirements or conditions that must be met before performing the test.*
> The board must be flashed with the latest software and/or reset prior to test execution, etc.

### Post-conditions

*Describe the expected state of the system after the test was executed, regardless of whether it failed or passed*
> After test execution, the test bed should close and the computer should be back to initial state, with the test results output to a file named test.txt on the desktop (and should be the only file on the desktop)

### Test Data

*Describe the data required as an input for the test*
> The test will automatically pull the latest code from the dev branch to make sure it compiles successfully

### Status:

To be updated with "Pass", "Fail", or "Blocked".

### Steps:

#### Step ID
#### Step Description
#### Test Date
#### Expected Results
#### Actual Results
#### Status
#### Additional Notes

### Notes:

*Any additional comments or observations.*
> I noticed the test execution briefly interrupted the connection to the internet, probably due to... but this didn't alter the test execution.
