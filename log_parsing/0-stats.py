#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics.
"""

import sys


def print_stats(total_size, status_codes):
    """Prints the computed statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()
            try:
                # Validate the line format and extract data
                if len(parts) > 2:
                    size = int(parts[-1])
                    status = int(parts[-2])
                    if status in status_codes:
                        status_codes[status] += 1
                    total_size += size
                else:
                    continue
            except (ValueError, IndexError):
                # Skip lines that do not have the expected integer format
                continue

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

    # Print final stats on normal exit
    print_stats(total_size, status_codes)
