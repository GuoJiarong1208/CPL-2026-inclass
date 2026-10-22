Get-ChildItem .\cases\*.in | ForEach-Object {
$got = Get-Content -Raw $_.FullName | .\scores
$want = Get-Content ([IO.Path]::ChangeExtension($_.FullName,".out"))
if (($LASTEXITCODE -eq 0) -and (($got -join "`n") -eq ($want -join "`n"))) {"PASS"} else {"FAIL"}
}