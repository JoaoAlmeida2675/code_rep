<#
.SYNOPSIS
    This script checks for empty cells in specified columns of an Excel sheet.
.DESCRIPTION
    The script opens an Excel file, selects a specific sheet, and checks for empty cells in specified columns.
.NOTES
    File Name      : ExcelDataValidation.ps1
    Prerequisite   : Microsoft Excel needs to be installed on the system and the Excel Import for PowerShell.
    Author         : João Pedro Almeida
    License        : This script is licensed under the MIT License - see the LICENSE.md file for details.
#>

# Function to get the column index from the column letter (A=1, B=2, etc.) - supports columns with multiple letters (e.g., AA, AB)
function Get-ColumnIndexFromLetter {
    param (
        [string]$letter
    )

    $letter = $letter.ToUpper()
    $alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    $columnIndex = 0

    for ($i = 0; $i -lt $letter.Length; $i++) {
        $character = $letter[$i]
        $characterIndex = $alphabet.IndexOf($character) + 1
        $columnIndex = $columnIndex * 26 + $characterIndex
    }

    return $columnIndex
}

# Open Excel and load the file
$excel = New-Object -ComObject Excel.Application
$excel.Visible = $true  # You can set this to $false if you want Excel to run in the background

$workbook = $excel.Workbooks.Open("path/to/your/excelfile")

if ($workbook -eq $null) {
    Write-Host "Failed to open the workbook."
    $excel.Quit()
    [System.Runtime.InteropServices.Marshal]::ReleaseComObject($excel) | Out-Null
    return
}

# Specify the sheet name
$sheetName = "YOUR SHEET NAME"

# Select the sheet by name
$sheet = $workbook.Sheets.Item($sheetName)

if ($sheet -eq $null) {
    Write-Host "Failed to select the worksheet."
    $workbook.Close()
    $excel.Quit()
    [System.Runtime.InteropServices.Marshal]::ReleaseComObject($workbook) | Out-Null
    [System.Runtime.InteropServices.Marshal]::ReleaseComObject($excel) | Out-Null
    return
}

$sheet.Select()

# Specify the columns to check (based on column letters)
$columnsToCheck = "B", "C", "D", "H", "I", "L", "M", "N", "O", "Q", "R", "T", "U", "Y", "Z", "AA", "AD", "AH", "AI", "AJ", "AK", "AM", "AN", "AO"

# Initialize a list to store the names of empty columns
$emptyColumnNames = @()

# Iterate through each specified column and check if the cell in row 6 is empty
foreach ($columnLetter in $columnsToCheck) {
    $columnIndex = Get-ColumnIndexFromLetter $columnLetter

    if ($columnIndex -eq 0) {
        Write-Host "Invalid column letter: $columnLetter"
        continue
    }

    $columnRange = $sheet.Cells.Item(1, $columnIndex)
    $cell = $sheet.Cells.Item(6, $columnIndex)

    if ($cell.Value2 -eq $null) {
        $emptyColumnNames += $columnRange.Value2
    }
}

# Check if empty cells were found
if ($emptyColumnNames.Count -eq 0) {
    [System.Windows.Forms.MessageBox]::Show("No empty cells in the specified columns. Everything is OK!", "Data Validation", [System.Windows.Forms.MessageBoxButtons]::OK, [System.Windows.Forms.MessageBoxIcon]::Information)
} else {
    $message = "Missing valid data in columns:`n"
    $message += $emptyColumnNames -join "`n"
    [System.Windows.Forms.MessageBox]::Show($message, "Data Validation", [System.Windows.Forms.MessageBoxButtons]::OK, [System.Windows.Forms.MessageBoxIcon]::Warning)
}

# Close Excel
$workbook.Close()
$excel.Quit()

# Release resources
[System.Runtime.InteropServices.Marshal]::ReleaseComObject($sheet) | Out-Null
[System.Runtime.InteropServices.Marshal]::ReleaseComObject($workbook) | Out-Null
[System.Runtime.InteropServices.Marshal]::ReleaseComObject($excel) | Out-Null

# Remove references to COM objects
Remove-Variable sheet
Remove-Variable workbook
Remove-Variable excel
