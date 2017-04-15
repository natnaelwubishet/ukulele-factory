Function Get-FileName($initialDirectory)
{
    [System.Reflection.Assembly]::LoadWithPartialName("System.windows.forms") | Out-Null

    $folderDialog = New-Object System.Windows.Forms.FolderBrowserDialog
    $folderDialog.ShowDialog() | Out-Null
    $folderDialog.SelectedPath
}

$inputfolder = Get-FileName "C:\"
Write-Output $inputfolder

# finally set path
$env:CMAKE_PREFIX_PATH = $inputfolder