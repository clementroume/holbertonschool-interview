#!/usr/bin/python3
"""
Module for validating if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Validates if a given list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): List of integers representing byte values.

    Returns:
        bool: True if the data is valid UTF-8, False otherwise.
    """
    # This variable keeps track of the number of continuation bytes we expect
    # to see. A value of 0 means we are expecting a new character's
    # starting byte.
    num_bytes = 0

    # Iterate over each integer (byte) in the input list.
    for byte in data:
        # We only consider the 8 least significant bits of each integer.
        byte = byte & 0xFF

        # If num_bytes is 0, we are at the beginning of a new character.
        if num_bytes == 0:
            # Check the first bits to determine the character's length.
            # 1-byte character: starts with '0' (e.g., 0xxxxxxx)
            if (byte >> 7) == 0b0:
                # This is a valid 1-byte character (ASCII). We expect the next
                # byte to be a new character, so num_bytes remains 0.
                continue
            # 2-byte character: starts with '110' (e.g., 110xxxxx)
            elif (byte >> 5) == 0b110:
                # We now expect 1 continuation byte.
                num_bytes = 1
            # 3-byte character: starts with '1110' (e.g., 1110xxxx)
            elif (byte >> 4) == 0b1110:
                # We now expect 2 continuation bytes.
                num_bytes = 2
            # 4-byte character: starts with '11110' (e.g., 11110xxx)
            elif (byte >> 3) == 0b11110:
                # We now expect 3 continuation bytes.
                num_bytes = 3
            else:
                # If the byte doesn't match any valid starting byte pattern,
                # the encoding is invalid.
                return False
        # If num_bytes is not 0, we are expecting a continuation byte.
        else:
            # A continuation byte must start with '10' (e.g., 10xxxxxx).
            if (byte >> 6) != 0b10:
                # If the byte does not have the valid continuation format,
                # the encoding is invalid.
                return False
            # If it's a valid continuation byte, decrement our counter.
            num_bytes -= 1

    # After checking all bytes, if num_bytes is 0, it means all multi-byte
    # characters were completed correctly.
    # If it's not 0, the data is incomplete.
    return num_bytes == 0
