# 可选：逐字比较 .in 对应的 .out；课堂批量测试可直接使用 CTest。
$ErrorActionPreference = 'Stop'
$courseRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Push-Location $courseRoot
try {
    & gcc -std=c11 -Wall -Wextra -Werror -pedantic .\scores.c -o .\scores.exe
    if ($LASTEXITCODE -ne 0) { throw 'Compilation failed.' }

    $failures = 0
    foreach ($case in (Get-ChildItem .\cases -Filter '*.in' | Sort-Object Name)) {
        $expectedPath = [IO.Path]::ChangeExtension($case.FullName, '.out')
        $expected = [IO.File]::ReadAllText($expectedPath).Replace("`r`n", "`n")
        $lines = & .\scores.exe $case.FullName
        $exitCode = $LASTEXITCODE
        $actual = if ($null -eq $lines) { '' } else { ($lines -join "`n") + "`n" }
        if ($exitCode -eq 0 -and $actual -ceq $expected) {
            Write-Host "PASS $($case.Name)"
        } else {
            Write-Host "FAIL $($case.Name)"
            Write-Host "Expected:`n$expected"
            Write-Host "Actual:`n$actual"
            $failures++
        }
    }

    if ($failures -ne 0) { exit 1 }
    Write-Host 'All tests passed.'
} finally {
    Pop-Location
}
