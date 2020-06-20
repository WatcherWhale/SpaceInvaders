$exists = Test-Path .\cmake-build-debug\Assets
if ($exists)
{
	echo "Removing previous folder."
	Remove-Item -Path .\cmake-build-debug\Assets -Force -Confirm:$false -Recurse | Out-Null
}

echo "Creating assets folder."
New-Item -path "cmake-build-debug" -name "Assets" -ItemType "directory" -Force -Confirm:$false | Out-Null

Copy-Item -Path .\Assets\* -Destination .\cmake-build-debug\Assets -Recurse -Force -Confirm:$false | Out-Null
echo "Copied files to build directory."