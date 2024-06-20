#!/usr/bin/python3

"""
Parses log file input from stdin
and calculates total file size and status code counts.

The script reads input from stdin,
parses each line using a regular expression, and
updates the total file size and status code counts accordingly.
It prints the current total file size and status code counts every 10 lines.

If the script is interrupted with a KeyboardInterrupt (e.g., Ctrl+C),
it prints the final total file size and status code counts.
"""

import sys

in_data = sys.stdin.read()
lines = in_data.splitlines()

# Initialize line count
line_count = 0
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


def print_status():

    # Print final status on interrupt
    print("File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print(code, end="")
            print(":", status_codes[code])

    # Iterate over input lines from stdin
for line in lines:
    try:
        # Parse line using split function
        parts = line.split(" ")
        total_size += int(parts[-1])

        if int(parts[-2]) in status_codes:
            status_codes[int(parts[-2])] += 1

        line_count += 1

        if line_count % 10 == 0:
            print_status()

    except Exception as e:
        continue

print_status()
