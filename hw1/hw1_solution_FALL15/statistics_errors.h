#ifndef H_ERRORS_H
#define H_ERRORS_H

/*
 * These errors should be handled properly by detecting them and
 * returning the proper status code by calling exit(enum error)
 */

enum error
{
	INCORRECT_COMMAND_LINE_ARGUMENTS = 1,
	FILE_FAILED_TO_OPEN,
	FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED,
	PARSING_ERROR_EMPTY_FILE, // indicates that zero numbers were found in the file
};

#endif