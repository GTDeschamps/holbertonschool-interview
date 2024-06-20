#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
Parses log file input from stdin and calculates total file size and status code counts.

The script reads input from stdin, parses each line using a regular expression, and
updates the total file size and status code counts accordingly. It prints the
current total file size and status code counts every 10 lines.

If the script is interrupted with a KeyboardInterrupt (e.g., Ctrl+C), it prints
the final total file size and status code counts.
"""

import sys
import re

# Initialize total file size and status code counts
total_size = 0
status_codes = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0,
}

# Initialize line count
line_count = 0

try:
    # Iterate over input lines from stdin
    for line in sys.stdin:
        line_count += 1
        # Parse line using regular expression
        match = re.match(r'^(\S+) - \[(.+)\] "(GET /projects/260 HTTP/1.1)" (\d{3}) (\d+)$', line)
        if match:
            # Extract status code and file size from match
            status_code = int(match.group(3))
            file_size = int(match.group(4))
            # Update total file size and status code counts
            total_size += file_size
            status_codes[status_code] += 1
        else:
            # Skip invalid lines
            continue

        # Print status every 10 lines
        if line_count % 10 == 0:
            print("Total file size: File size:", total_size)
            for code in sorted(status_codes.keys()):
                if status_codes[code] > 0:
                    print(code, ":", status_codes[code])

except KeyboardInterrupt:
    # Print final status on interrupt
    print("Total file size: File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(code, ":", status_codes[code])
