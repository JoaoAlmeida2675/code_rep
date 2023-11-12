# Excel Data Validation PowerShell Script

This PowerShell script checks for empty cells in specified columns of an Excel sheet.

## Prerequisites

Before running the script, make sure to import the `ImportExcel` module:
Import-Module ImportExcel


##Functions

1. Get-ColumnIndexFromLetter
Description:

Converts a letter or set of letters to uppercase.
Calculates the corresponding column index based on the alphabet.
Supports columns with multiple letters (e.g., AA, AB).
Returns the column index.
2. Open and Load the Excel File
Description:

Creates an instance of Excel.
Makes Excel visible.
Opens an Excel workbook located at the specified path.
3. Select the Sheet and Specify the Columns to Check
Description:

Sets the sheet name to "YOUR SHEET NAME".
Selects the sheet with the specified name.
Specifies a set of columns to be checked.
4. Check Empty Cells
Description:

Initializes a list to store the names of empty columns.
Iterates over each specified column letter.
Gets the column index using the function defined earlier.
If the column index is zero, displays a message about an invalid column and continues to the next iteration.
Gets a range of cells in row 1 and the specified column.
Gets the cell in row 6 and the specified column.
If the cell value is null, adds the column name to the list of empty columns.
5. Display Result Message
Description:

Checks if empty cells were found.
If no empty cells are found, displays a message stating that everything is OK.
If empty cells are found, creates a message listing the columns with missing data and displays a warning.
6. Close Excel and Release Resources
Description:

Closes the workbook and Excel.
Releases resources associated with Excel objects.
7. Remove COM Object References
Description:

Removes the variables storing references to COM objects to further release resources.
