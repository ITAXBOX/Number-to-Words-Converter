# Number to Words Converter (num2words)

## Overview
This project is a C program that converts numeric values into their English word equivalents, supporting numbers from zero up to duotrigintillion (10^99). It uses a dictionary-based approach with customizable mappings for flexibility.

## Features
- Supports both default and custom dictionary files.
- Handles numbers up to 99 digits.
- Formats compound numbers correctly (e.g., "twenty-one").
- Includes robust error handling.
- Ensures memory-safe implementation.

## Installation
```bash
git clone https://github.com/ITAXBOX/Number-to-Words-Converter
cd Number-to-Words-Converter
make
```

## Usage
### Basic Syntax
```bash
.\number-to-words.exe [dictionary_file] number
```

### Examples
#### Using the default dictionary:
```bash
.\number-to-words.exe 42
# Output: forty-two
```

#### Using a custom dictionary:
```bash
.\number-to-words.exe custom.dict 123456789
# Output: one hundred twenty-three million four hundred fifty-six thousand seven hundred eighty-nine
```

#### Very large number:
```bash
.\number-to-words.exe 1000000000000000000000000000000000
# Output: one decillion
```

## Dictionary Specification
### Required Entries
The dictionary must include:
- Units: 0-9
- Teens: 10-19
- Tens: 20-90
- "Hundred"
- Scale numbers: thousand, million, billion, ..., duotrigintillion

### File Format
Each line should follow this format:
```
[number]: [word_representation]
```

#### Example:
```
0: zero
1: one
...
20: twenty
21: twenty-one
...
100: hundred
1000: thousand
1000000: million
...
1000000000000000000000000000000000: decillion
```

### Custom Dictionary Rules
- One entry per line.
- Numbers precede the colon, words follow.
- Leading/trailing spaces are trimmed automatically.
- Empty lines are ignored.
- Comments can be added using `#`.

## Error Handling
### Input Errors
```bash
.\number-to-words.exe
# Error: .\number-to-words.exe [dict] number

.\number-to-words.exe abc
# Error
```

### Dictionary Errors
```bash
.\number-to-words.exe missing.dict 123
# Dict Error

.\number-to-words.exe corrupt.dict 456
# Dict Error
```

## Implementation Details
### Number Processing
- Validates input.
- Removes leading zeros.
- Groups digits into sets of three.
- Looks up dictionary entries for each component.
- Applies proper hyphenation for compound numbers.

### Memory Management
- Frees all allocated memory.
- Protects against buffer overflows.
- Handles strings safely.

### Performance Notes
- Linear dictionary search (O(n) complexity).
- Processing may take longer for very large numbers (>15 digits).
- Dictionary is read sequentially for each conversion.

## Testing
The program has been tested with:
- Single-digit numbers.
- Large numbers (up to 10^99).
- Edge cases (e.g., zero, one).
- Various dictionary configurations.

## Limitations
- Supports English only.
- Requires a complete dictionary file.
- Maximum number length: 99 digits.

## Sample Output
```bash
> .\number-to-words.exe 120000045
# Output: one hundred twenty million forty-five

> .\number-to-words.exe 1000000000000000000
# Output: one quintillion
```

## License
This project is licensed under the MIT License.
