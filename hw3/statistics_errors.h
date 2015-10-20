#ifndef H_ERRORS_H
#define H_ERRORS_H

/*
 * These errors should be handled properly by detecting them and
 * returning the proper status code by calling exit(enum error)
 */

enum error
{
	INCORRECT_COMMAND_LINE_ARGUMENTS = 1,
        INVALID_COMMAND_INPUT,
	LOG_FILE_FAILED_TO_OPEN,
	LOG_FILE_FAILED_TO_CLOSE,
        PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED_LOG,
        PARSING_ERROR_COMPUTER_NAME_INVALID_LOG,
        PARSING_ERROR_TIME_DECREASING_LOG,
	OUTPUT_FILE_FAILED_TO_OPEN,
	OUTPUT_FILE_FAILED_TO_CLOSE,
};

#endif

