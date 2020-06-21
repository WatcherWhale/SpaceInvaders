$exists = Test-Path .\cmake-build-debug\texturepacks
if ($exists)
{
	Write-Output "Removing previous folder."
	Remove-Item -Path .\cmake-build-debug\texturepacks -Force -Confirm:$false -Recurse | Out-Null
}

Write-Output "Creating texturepacks folder."
New-Item -path "cmake-build-debug" -name "texturepacks" -ItemType "directory" -Force -Confirm:$false | Out-Null

Copy-Item -Path .\texturepacks\* -Destination .\cmake-build-debug\texturepacks -Recurse -Force -Confirm:$false | Out-Null
Write-Output "Copied files to build directory."

Copy-Item -path .\settings.json -Destination .\cmake-build-debug\settings.json -Force -Confirm:$false | Out-Null
Write-Output "Copied settings to build directory."