# ExcelDataValidation

This PowerShell script checks for empty cells in specified columns of an Excel sheet.

## Prerequisites
- Microsoft Excel needs to be installed on the system.
- Excel Import for PowerShell module.

> **Note**: This script already has the columns and the row selected. Make sure to change them according to your specific needs.


## Usage
1. Run the command `Import-Module ImportExcel` to import the required module.
2. Open the script file `ExcelDataValidation.ps1` in a text editor.
3. Modify the following sections according to your needs:
   - Specify the path to your Excel file.
   - Specify the sheet name.
   - Specify the columns to check (based on column letters).
4. Save the changes to the script file.
5. Open a PowerShell terminal and navigate to the directory containing the script.
6. Run the command `.\ExcelDataValidation.ps1` to execute the script.
7. Review the output to see if any empty cells are found in the specified columns.
8. The script will display a message indicating whether everything is OK or if there are missing data in the columns.

## License
This script is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.

## Author
- Name: João Pedro Almeida
