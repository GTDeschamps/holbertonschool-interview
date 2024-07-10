#!/usr/bin/python3

def validUTF8(data):
    num_bytes = 0

    for byte in data:
        byte = bin(byte)[2:].zfill(8)  # Convert byte to binary and pad with zeros to 8 bits

        if num_bytes == 0:
            if byte.startswith('0'):
                continue
            elif byte.startswith('110'):
                num_bytes = 1
            elif byte.startswith('1110'):
                num_bytes = 2
            elif byte.startswith('11110'):
                num_bytes = 3
            else:
                return False
        else:
            if not byte.startswith('10'):
                return False
            num_bytes -= 1

    return num_bytes == 0
