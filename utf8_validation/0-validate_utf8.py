#!/usr/bin/python3
"""
Definition of validation UTF8
"""


def validUTF8(data):
    """
    Check if a given data set represents a valid UTF-8 encoding.

    Args:
    data (list): List of integers representing bytes of data

    Returns:
    bool: True if data is a valid UTF-8 encoding, else False
    """
    num_bytes = 0  # Counter to track the number of bytes in a UTF-8 character

    for byte in data:
        byte = bin(byte)[2:].zfill(8)
        # Convert byte to binary and pad with zeros to 8 bits

        if num_bytes == 0:
            # Check the first few bits to determine the number of bytes
            if byte.startswith('0'):
                continue
            elif byte.startswith('110'):
                num_bytes = 1
            elif byte.startswith('1110'):
                num_bytes = 2
            elif byte.startswith('11110'):
                num_bytes = 3
            else:
                return False  # Invalid UTF-8 encoding found
        else:
            if not byte.startswith('10'):
                return False  # Invalid continuation byte
            num_bytes -= 1  # Decrease the remaining bytes to process

    return num_bytes == 0  # Check if all character bytes have been processed
