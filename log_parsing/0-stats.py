#!/usr/bin/python3

import sys
import re

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

line_count = 0

try:
    for line in sys.stdin:
        line_count += 1
        match = re.match(r'^(\S+) - \[(.+)\] "(GET /projects/260 HTTP/1.1)" (\d{3}) (\d+)$', line)
        if match:
            status_code = int(match.group(3))
            file_size = int(match.group(4))
            total_size += file_size
            status_codes[status_code] += 1
        else:
            continue

        if line_count % 10 == 0:
            print("Total file size: File size:", total_size)
            for code in sorted(status_codes.keys()):
                if status_codes[code] > 0:
                    print(code, ":", status_codes[code])

except KeyboardInterrupt:
    print("Total file size: File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(code, ":", status_codes[code])
