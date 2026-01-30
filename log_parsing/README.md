# Log Parsing

## Description

This project consists of a Python script that reads logs from standard input (`stdin`), line by line, and computes metrics in real-time.

The script parses each line to extract the file size and HTTP status code. Cumulative statistics are displayed after every 10 lines are read and also when a keyboard interruption (`CTRL + C`) is detected.

## Implementation Details

The script is designed to process a continuous data stream and provide periodic reports.

### Input Format

The script expects a very specific line format to be processed: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`

Any line that does not strictly adhere to this format is ignored, and the script moves on to the next one without raising an error.

### Script Logic

- **Total file size:** A variable accumulates the sum of the file sizes (`<file size>`) from all valid lines read since the script started.
- **Number of lines by status code:** A dictionary stores the count for each valid status code encountered. The possible status codes are: `200, 301, 400, 401, 403, 404, 405, 500`.
- **Statistics display:** A dedicated function prints the total file size, followed by the counts for each status code that has appeared, sorted in ascending order.
- **Interrupt handling:** The script uses a `try...except KeyboardInterrupt` block to ensure that the final statistics are printed cleanly before exiting in case of a manual interruption by the user.

## Files

### `0-stats.py`

The main script that contains all the logic for parsing and calculating metrics. It is designed to be run from the command line and is protected from being executed if imported as a module in another script.

### `0-generator.py`

An auxiliary script that generates log lines in the expected format and writes them to standard output (`stdout`). It is used to simulate a real-time data stream to test `0-stats.py`.

## Usage

To run the script, you must redirect the output of the log generator to the input of the parsing script using a pipe (`|`).

**Example command:**

``` bash
./0-generator.py | ./0-stats.py
```

This command starts the generator, and each line it produces is immediately sent as input to the `0-stats.py` script to be processed.
