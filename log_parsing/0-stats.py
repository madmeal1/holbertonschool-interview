#!/usr/bin/python3
"""
Reads stdin line by line and prints metrics
"""

import re
import sys


STATUSES = (200, 301, 400, 401, 403, 404, 405, 500)

LOG_RE = re.compile(
    r'^(\d{1,3}(?:\.\d{1,3}){3}) - \[(.*?)\] '
    r'"GET /projects/260 HTTP/1\.1" (\S+) (\S+)$'
)


def print_stats(total_size, counts):
    """Print total size and status counts in ascending status order"""
    print("File size: {}".format(total_size))
    for code in STATUSES:
        if counts.get(code, 0):
            print("{}: {}".format(code, counts[code]))


def main():
    """Main entrypoint: parse lines, accumulate metrics, print periodically"""
    total_size = 0
    counts = {}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            line = line.rstrip("\n")

            match = LOG_RE.match(line)
            if match:
                status_str = match.group(3)
                size_str = match.group(4)

                try:
                    total_size += int(size_str)
                except (TypeError, ValueError):
                    pass

                try:
                    status = int(status_str)
                    if status in STATUSES:
                        counts[status] = counts.get(status, 0) + 1
                except (TypeError, ValueError):
                    pass

            if line_count % 10 == 0:
                print_stats(total_size, counts)

    except KeyboardInterrupt:
        print_stats(total_size, counts)
        return
    else:
        print_stats(total_size, counts)


if __name__ == "__main__":
    main()
