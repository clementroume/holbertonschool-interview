# **UTF-8 Validation**

## **Description**

This project implements a Python function that determines if a given dataset represents a valid **UTF-8** encoding. UTF-8 is a variable-width character encoding, and this function validates that the byte sequence follows its formatting rules.

## **UTF-8 Encoding Rules**

The function analyzes a list of integers where each integer represents one byte. It validates the sequences based on the following rules:

1. **Single-byte character**: A single-byte character has the format `0xxxxxxx`. The first bit must be `0`.

2. **Multi-byte character**: For an `n`-byte character, the first byte must start with `n` ones followed by a zero. The following `n-1` bytes must all start with `10`.
    - **2 bytes**: `110xxxxx 10xxxxxx`
    - **3 bytes**: `1110xxxx 10xxxxxx 10xxxxxx`
    - **4 bytes**: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`

3. **Data Validation**: Only the **8 least significant bits** of each integer in the data list are considered for validation.

## **Files**

### `0-validate_utf8.py`

- Implements the core logic:

  - `validUTF8(data)`: Analyzes the list of integers (`data`) and returns `True` if the sequence represents a valid UTF-8 encoding, otherwise `False`.

### `0-main.py`

- Contains a test program to verify the `validUTF8` function with multiple datasets.

## **Execution**

To test the function, run the main file from your terminal:

```sh
./0-main.py
```

### **Example Output**

```sh
$ ./0-main.py
True
True
False
```
