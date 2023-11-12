# PowerShell Script: ExcelDataValidation

> **Note**: To use the script, run the code `Import-Module ImportExcel` first.
> 
> **Note**: This script already has the columns and the row selected. Make sure to change them according to your specific needs.


## 1. Function Get-ColumnIndexFromLetter:
- Receives a letter or set of letters as a parameter.
- Converts the letter to uppercase.
- Initializes a variable $alphabet with the letters of the alphabet.
- Initializes $columnIndex as zero.
- Iterates through each character in the provided letter.
- For each character, calculates the corresponding index in the alphabet and updates $columnIndex by multiplying it by 26 (number of letters in the alphabet) and adding the index of the character.
- Returns the column index.

## 2. Open and Load the Excel File:
- Creates an instance of Excel.
- Makes Excel visible.
- Opens an Excel workbook located at the specified path.

## 3. Select the Sheet and Specify the Columns to Check:
- Sets the sheet name to "YOUR SHEET NAME".
- Selects the sheet with the specified name.
- Specifies a set of columns to be checked.

## 4. Check Empty Cells:
- Initializes a list to store the names of empty columns.
- Iterates over each specified column letter.
- Gets the column index using the function defined earlier.
- If the column index is zero, displays a message about an invalid column and continues to the next iteration.
- Gets a range of cells in row 1 and the specified column.
- Gets the cell in row 6 and the specified column.
- If the cell value is null, adds the column name to the list of empty columns.

## 5. Display Result Message:
- Checks if empty cells were found.
- If no empty cells are found, displays a message stating that everything is OK.
- If empty cells are found, creates a message listing the columns with missing data and displays a warning.

## 6. Close Excel and Release Resources:
- Closes the workbook and Excel.
- Releases resources associated with Excel objects.

## 7. Remove COM Object References:
- Removes the variables storing references to COM objects to further release resources.

## License

See the [LICENSE.md](LICENSE.md) file for details.
