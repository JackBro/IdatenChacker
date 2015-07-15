Attribute VB_Name = "Module1"
Sub SetNum()
Dim retu As Integer
Dim gyou As Integer

Range("A2").Select
For retu = 1 To 220
    For gyou = 2 To 49
        With Cells(gyou, retu)
        Select Case .Interior.ColorIndex
            Case 53
                .Value = 1
            Case 3
                .Value = 3
            Case 43
                .Value = 2
            Case 33
                .Value = 5
            Case 46
                .Value = 7
            Case 40
                .Value = 8
            Case 19
                .Value = 9
            Case 16
                .Value = -1
            Case 55
                .Value = "{ " & 7
            Case 17
                .Value = 7 & " }"
            Case Else
                .Value = 0
        End Select
        End With
    Next
Next

End Sub

Function CellColor(CELL)
CellColor = CELL.Interior.ColorIndex
End Function
