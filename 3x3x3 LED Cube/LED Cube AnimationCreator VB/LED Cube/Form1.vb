Imports System.IO

Public Class Form1

    Dim images(26) As Integer
    Dim Frame As Integer = 1
    Dim Frameanzahl As Integer = 1
    Dim Framelast As Integer = 1
    Dim FrameNr As String
    Dim FrameNm As String



    Dim wiederholungen As Integer


    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        FrameNr = "Frame" & Frame & ".txt"
        wiederholungen = TextBox3.Text

        Dim fs As New FileStream(FrameNr, FileMode.Create)
        Dim sw As New StreamWriter(fs)

        For b = 0 To 26 Step 1
            sw.WriteLine(images(b))
        Next
        sw.WriteLine(wiederholungen)

        sw.Close()
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        FrameNr = "Frame" & Frame & ".txt"

        Dim fs2 As New FileStream(FrameNr, FileMode.OpenOrCreate)
        Dim sr As New StreamReader(fs2)

        For b = 0 To 26 Step 1
            images(b) = sr.ReadLine()
        Next

        wiederholungen = sr.ReadLine()

        sr.Close()

        LED_aktualisieren()


        'Für Buttonrotation ROW1
        Dim w As Integer = Label6.Width ' Breite des Controls
        Dim h As Integer = Label6.Height ' Höhe des Controls
        Dim myBitmap As New Bitmap(w, h)  'Es wird ein Bild des Labels erzeugt
        Label6.DrawToBitmap(myBitmap, Rectangle.FromLTRB(0, 0, w, h))  'hier wird es gemacht
        myBitmap.RotateFlip(RotateFlipType.Rotate90FlipXY)       'und hier gedreht
        Button6.Image = myBitmap

        'Für Buttonrotation ROW2
        Dim w1 As Integer = Label8.Width ' Breite des Controls
        Dim h1 As Integer = Label8.Height ' Höhe des Controls
        Dim myBitmap1 As New Bitmap(w1, h1)  'Es wird ein Bild des Labels erzeugt
        Label8.DrawToBitmap(myBitmap1, Rectangle.FromLTRB(0, 0, w1, h1))  'hier wird es gemacht
        myBitmap1.RotateFlip(RotateFlipType.Rotate90FlipXY)       'und hier gedreht
        Button8.Image = myBitmap1

        'Für Buttonrotation ROW3
        Dim w2 As Integer = Label9.Width ' Breite des Controls
        Dim h2 As Integer = Label9.Height ' Höhe des Controls
        Dim myBitmap2 As New Bitmap(w2, h2)  'Es wird ein Bild des Labels erzeugt
        Label9.DrawToBitmap(myBitmap2, Rectangle.FromLTRB(0, 0, w2, h2))  'hier wird es gemacht
        myBitmap2.RotateFlip(RotateFlipType.Rotate90FlipXY)       'und hier gedreht
        Button9.Image = myBitmap2


    End Sub

#Region "buttons"

#Region "reihen und Spalten"

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If images(0) = 1 Then
            For i = 0 To 26 Step 1
                images(i) = 0
            Next
        Else
            For i = 0 To 26 Step 1
                images(i) = 1
            Next
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        If images(0) = 1 Then
            For i = 0 To 8
                images(i) = 0
            Next
        Else
            For i = 0 To 8
                images(i) = 1
            Next
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        If images(9) = 1 Then
            For i = 9 To 17
                images(i) = 0
            Next
        Else
            For i = 9 To 17
                images(i) = 1
            Next
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        If images(18) = 1 Then
            For i = 18 To 26
                images(i) = 0
            Next
        Else
            For i = 18 To 26
                images(i) = 1
            Next
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        If images(0) = 1 Then
            images(0) = 0
            images(9) = 0
            images(18) = 0
        Else

            images(0) = 1
            images(9) = 1
            images(18) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        If images(1) = 1 Then
            images(1) = 0
            images(10) = 0
            images(19) = 0
        Else

            images(1) = 1
            images(10) = 1
            images(19) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        If images(2) = 1 Then
            images(2) = 0
            images(11) = 0
            images(20) = 0
        Else

            images(2) = 1
            images(11) = 1
            images(20) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        If images(3) = 1 Then
            images(3) = 0
            images(12) = 0
            images(21) = 0
        Else

            images(3) = 1
            images(12) = 1
            images(21) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button14.Click
        If images(4) = 1 Then
            images(4) = 0
            images(13) = 0
            images(22) = 0
        Else

            images(4) = 1
            images(13) = 1
            images(22) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button15.Click
        If images(5) = 1 Then
            images(5) = 0
            images(14) = 0
            images(23) = 0
        Else

            images(5) = 1
            images(14) = 1
            images(23) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        If images(6) = 1 Then
            images(6) = 0
            images(15) = 0
            images(24) = 0
        Else

            images(6) = 1
            images(15) = 1
            images(24) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        If images(7) = 1 Then
            images(7) = 0
            images(16) = 0
            images(25) = 0
        Else

            images(7) = 1
            images(16) = 1
            images(25) = 1
        End If
        LED_aktualisieren()
    End Sub

    Private Sub Button18_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button18.Click
        If images(8) = 1 Then
            images(8) = 0
            images(17) = 0
            images(26) = 0
        Else

            images(8) = 1
            images(17) = 1
            images(26) = 1
        End If
        LED_aktualisieren()
    End Sub

#End Region


    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        For i = 0 To Frameanzahl Step 1
            Dim framename As String = "Frame" & i & ".txt"
            System.IO.File.Delete(framename)
        Next
        For i = 0 To 26 Step 1
            images(i) = 0
            LED_aktualisieren()
        Next
        Frame = 1
        Frameanzahl = 1
        TextBox1.Text = "Frame: " & Frame
        TextBox2.Text = "Frames: " & Frameanzahl
        code.Clear()
        TextBox3.Text = 100

    End Sub

#End Region

#Region "pbs"
    Private Sub PictureBox1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox1.Click
        If images(1 - 1) = 0 Then
            PictureBox1.BackgroundImage = My.Resources.Led_an
            images(1 - 1) = 1
        Else
            PictureBox1.BackgroundImage = My.Resources.Led_aus
            images(1 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox2.Click
        If images(2 - 1) = 0 Then
            PictureBox2.BackgroundImage = My.Resources.Led_an
            images(2 - 1) = 1
        Else
            PictureBox2.BackgroundImage = My.Resources.Led_aus
            images(2 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox3.Click
        If images(3 - 1) = 0 Then
            PictureBox3.BackgroundImage = My.Resources.Led_an
            images(3 - 1) = 1
        Else
            PictureBox3.BackgroundImage = My.Resources.Led_aus
            images(3 - 1) = 0
        End If
    End Sub

    Private Sub PictureBox4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox4.Click
        If images(4 - 1) = 0 Then
            PictureBox4.BackgroundImage = My.Resources.Led_an
            images(4 - 1) = 1
        Else
            PictureBox4.BackgroundImage = My.Resources.Led_aus
            images(4 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox5.Click
        If images(4) = 0 Then
            PictureBox5.BackgroundImage = My.Resources.Led_an
            images(5 - 1) = 1
        Else
            PictureBox5.BackgroundImage = My.Resources.Led_aus
            images(5 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox6.Click
        If images(5) = 0 Then
            PictureBox6.BackgroundImage = My.Resources.Led_an
            images(6 - 1) = 1
        Else
            PictureBox6.BackgroundImage = My.Resources.Led_aus
            images(6 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox7.Click
        If images(6) = 0 Then
            PictureBox7.BackgroundImage = My.Resources.Led_an
            images(7 - 1) = 1
        Else
            PictureBox7.BackgroundImage = My.Resources.Led_aus
            images(7 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox8.Click
        If images(7) = 0 Then
            PictureBox8.BackgroundImage = My.Resources.Led_an
            images(8 - 1) = 1
        Else
            PictureBox8.BackgroundImage = My.Resources.Led_aus
            images(8 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox9.Click
        If images(8) = 0 Then
            PictureBox9.BackgroundImage = My.Resources.Led_an
            images(9 - 1) = 1
        Else
            PictureBox9.BackgroundImage = My.Resources.Led_aus
            images(9 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox10.Click
        If images(9) = 0 Then
            PictureBox10.BackgroundImage = My.Resources.Led_an
            images(10 - 1) = 1
        Else
            PictureBox10.BackgroundImage = My.Resources.Led_aus
            images(10 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox11.Click
        If images(10) = 0 Then
            PictureBox11.BackgroundImage = My.Resources.Led_an
            images(11 - 1) = 1
        Else
            PictureBox11.BackgroundImage = My.Resources.Led_aus
            images(11 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox12.Click
        If images(11) = 0 Then
            PictureBox12.BackgroundImage = My.Resources.Led_an
            images(12 - 1) = 1
        Else
            PictureBox12.BackgroundImage = My.Resources.Led_aus
            images(12 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox13.Click
        If images(12) = 0 Then
            PictureBox13.BackgroundImage = My.Resources.Led_an
            images(13 - 1) = 1
        Else
            PictureBox13.BackgroundImage = My.Resources.Led_aus
            images(13 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox14.Click
        If images(13) = 0 Then
            PictureBox14.BackgroundImage = My.Resources.Led_an
            images(14 - 1) = 1
        Else
            PictureBox14.BackgroundImage = My.Resources.Led_aus
            images(14 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox15.Click
        If images(14) = 0 Then
            PictureBox15.BackgroundImage = My.Resources.Led_an
            images(15 - 1) = 1
        Else
            PictureBox15.BackgroundImage = My.Resources.Led_aus
            images(15 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox16.Click
        If images(15) = 0 Then
            PictureBox16.BackgroundImage = My.Resources.Led_an
            images(16 - 1) = 1
        Else
            PictureBox16.BackgroundImage = My.Resources.Led_aus
            images(16 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox17.Click
        If images(16) = 0 Then
            PictureBox17.BackgroundImage = My.Resources.Led_an
            images(17 - 1) = 1
        Else
            PictureBox17.BackgroundImage = My.Resources.Led_aus
            images(17 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox18_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox18.Click
        If images(17) = 0 Then
            PictureBox18.BackgroundImage = My.Resources.Led_an
            images(18 - 1) = 1
        Else
            PictureBox18.BackgroundImage = My.Resources.Led_aus
            images(18 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox19_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox19.Click
        If images(18) = 0 Then
            PictureBox19.BackgroundImage = My.Resources.Led_an
            images(19 - 1) = 1
        Else
            PictureBox19.BackgroundImage = My.Resources.Led_aus
            images(19 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox20_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox20.Click
        If images(19) = 0 Then
            PictureBox20.BackgroundImage = My.Resources.Led_an
            images(20 - 1) = 1
        Else
            PictureBox20.BackgroundImage = My.Resources.Led_aus
            images(20 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox21_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox21.Click
        If images(20) = 0 Then
            PictureBox21.BackgroundImage = My.Resources.Led_an
            images(21 - 1) = 1
        Else
            PictureBox21.BackgroundImage = My.Resources.Led_aus
            images(21 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox22_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox22.Click
        If images(21) = 0 Then
            PictureBox22.BackgroundImage = My.Resources.Led_an
            images(22 - 1) = 1
        Else
            PictureBox22.BackgroundImage = My.Resources.Led_aus
            images(22 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox23_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox23.Click
        If images(22) = 0 Then
            PictureBox23.BackgroundImage = My.Resources.Led_an
            images(23 - 1) = 1
        Else
            PictureBox23.BackgroundImage = My.Resources.Led_aus
            images(23 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox24_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox24.Click
        If images(23) = 0 Then
            PictureBox24.BackgroundImage = My.Resources.Led_an
            images(24 - 1) = 1
        Else
            PictureBox24.BackgroundImage = My.Resources.Led_aus
            images(24 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox25_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox25.Click
        If images(24) = 0 Then
            PictureBox25.BackgroundImage = My.Resources.Led_an
            images(25 - 1) = 1
        Else
            PictureBox25.BackgroundImage = My.Resources.Led_aus
            images(25 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox26_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox26.Click
        If images(25) = 0 Then
            PictureBox26.BackgroundImage = My.Resources.Led_an
            images(26 - 1) = 1
        Else
            PictureBox26.BackgroundImage = My.Resources.Led_aus
            images(26 - 1) = 0
        End If
    End Sub
    Private Sub PictureBox27_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox27.Click
        If images(26) = 0 Then
            PictureBox27.BackgroundImage = My.Resources.Led_an
            images(27 - 1) = 1
        Else
            PictureBox27.BackgroundImage = My.Resources.Led_aus
            images(27 - 1) = 0
        End If
    End Sub
#End Region

    Sub LED_aktualisieren()
        TextBox3.Text = wiederholungen
        If images(1 - 1) = 1 Then
            PictureBox1.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox1.BackgroundImage = My.Resources.Led_aus
        End If
        If images(2 - 1) = 1 Then
            PictureBox2.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox2.BackgroundImage = My.Resources.Led_aus
        End If
        If images(3 - 1) = 1 Then
            PictureBox3.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox3.BackgroundImage = My.Resources.Led_aus
        End If
        If images(4 - 1) = 1 Then
            PictureBox4.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox4.BackgroundImage = My.Resources.Led_aus
        End If
        If images(5 - 1) = 1 Then
            PictureBox5.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox5.BackgroundImage = My.Resources.Led_aus
        End If
        If images(6 - 1) = 1 Then
            PictureBox6.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox6.BackgroundImage = My.Resources.Led_aus
        End If
        If images(7 - 1) = 1 Then
            PictureBox7.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox7.BackgroundImage = My.Resources.Led_aus
        End If
        If images(8 - 1) = 1 Then
            PictureBox8.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox8.BackgroundImage = My.Resources.Led_aus
        End If
        If images(9 - 1) = 1 Then
            PictureBox9.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox9.BackgroundImage = My.Resources.Led_aus
        End If
        If images(10 - 1) = 1 Then
            PictureBox10.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox10.BackgroundImage = My.Resources.Led_aus
        End If
        If images(11 - 1) = 1 Then
            PictureBox11.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox11.BackgroundImage = My.Resources.Led_aus
        End If
        If images(12 - 1) = 1 Then
            PictureBox12.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox12.BackgroundImage = My.Resources.Led_aus
        End If
        If images(13 - 1) = 1 Then
            PictureBox13.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox13.BackgroundImage = My.Resources.Led_aus
        End If
        If images(14 - 1) = 1 Then
            PictureBox14.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox14.BackgroundImage = My.Resources.Led_aus
        End If
        If images(15 - 1) = 1 Then
            PictureBox15.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox15.BackgroundImage = My.Resources.Led_aus
        End If
        If images(16 - 1) = 1 Then
            PictureBox16.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox16.BackgroundImage = My.Resources.Led_aus
        End If
        If images(17 - 1) = 1 Then
            PictureBox17.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox17.BackgroundImage = My.Resources.Led_aus
        End If
        If images(18 - 1) = 1 Then
            PictureBox18.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox18.BackgroundImage = My.Resources.Led_aus
        End If
        If images(19 - 1) = 1 Then
            PictureBox19.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox19.BackgroundImage = My.Resources.Led_aus
        End If
        If images(20 - 1) = 1 Then
            PictureBox20.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox20.BackgroundImage = My.Resources.Led_aus
        End If
        If images(21 - 1) = 1 Then
            PictureBox21.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox21.BackgroundImage = My.Resources.Led_aus
        End If
        If images(22 - 1) = 1 Then
            PictureBox22.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox22.BackgroundImage = My.Resources.Led_aus
        End If
        If images(23 - 1) = 1 Then
            PictureBox23.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox23.BackgroundImage = My.Resources.Led_aus
        End If
        If images(24 - 1) = 1 Then
            PictureBox24.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox24.BackgroundImage = My.Resources.Led_aus
        End If
        If images(25 - 1) = 1 Then
            PictureBox25.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox25.BackgroundImage = My.Resources.Led_aus
        End If
        If images(26 - 1) = 1 Then
            PictureBox26.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox26.BackgroundImage = My.Resources.Led_aus
        End If
        If images(27 - 1) = 1 Then
            PictureBox27.BackgroundImage = My.Resources.Led_an
        Else
            PictureBox27.BackgroundImage = My.Resources.Led_aus
        End If
    End Sub



#Region "Frames"
    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        FrameNr = "Frame" & Frame & ".txt"
        wiederholungen = TextBox3.Text

        Dim fs As New FileStream(FrameNr, FileMode.Create)
        Dim sw As New StreamWriter(fs)

        For b = 0 To 26 Step 1
            sw.WriteLine(images(b))
        Next
        sw.WriteLine(wiederholungen)

        sw.Close()


        Frame += 1
        Framelast = Frame
        If Frameanzahl < Framelast Then
            Frameanzahl = Framelast
        End If
        FrameNr = "Frame" & Frame & ".txt"

        Dim fs2 As New FileStream(FrameNr, FileMode.OpenOrCreate)
        Dim sr As New StreamReader(fs2)

        For b = 0 To 26 Step 1
            images(b) = sr.ReadLine()
        Next
        wiederholungen = sr.ReadLine()

        sr.Close()

        LED_aktualisieren()
        If wiederholungen <= 0 Then
            wiederholungen = 100
        End If

        TextBox1.Text = "Frame: " & Frame
        TextBox2.Text = "Frames: " & Frameanzahl
        TextBox3.Text = wiederholungen

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        FrameNr = "Frame" & Frame & ".txt"
        wiederholungen = TextBox3.Text

        Dim fs As New FileStream(FrameNr, FileMode.Create)
        Dim sw As New StreamWriter(fs)

        For b = 0 To 26 Step 1
            sw.WriteLine(images(b))
        Next
        sw.WriteLine(wiederholungen)

        sw.Close()


        Frame -= 1

        If Frame < 1 Then
            Frame = 1
        End If

        FrameNr = "Frame" & Frame & ".txt"

        Dim fs2 As New FileStream(FrameNr, FileMode.OpenOrCreate)
        Dim sr As New StreamReader(fs2)

        For b = 0 To 26 Step 1
            images(b) = sr.ReadLine()
        Next
        wiederholungen = sr.ReadLine()

        sr.Close()

        LED_aktualisieren()

        TextBox1.Text = "Frame: " & Frame
        TextBox3.Text = wiederholungen
    End Sub
#End Region



    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        FrameNr = "Frame" & Frame & ".txt"
        wiederholungen = TextBox3.Text

        Dim fs2 As New FileStream(FrameNr, FileMode.Create)
        Dim sw As New StreamWriter(fs2)

        For b = 0 To 26 Step 1
            sw.WriteLine(images(b))
        Next
        sw.WriteLine(wiederholungen)

        sw.Close()

        Frame -= 1

        If Frame < 1 Then
            Frame = 1
        End If


        code.Clear()
        code.Text += "int led[] = {5,9,10,4,2,3,8,7,6};" + vbCrLf + "int row[] = {13,12,11};" + vbCrLf + "void setup(){" + vbCrLf + "int pin;" + vbCrLf _
                     + "for (pin=0; pin<9; pin++) {" + vbCrLf + "pinMode( led[pin], OUTPUT);" + vbCrLf + "}" + vbCrLf + vbCrLf + "for (pin=0; pin<3; pin++) {" + vbCrLf _
                     + "pinMode( row[pin], OUTPUT );" + vbCrLf + "}" + vbCrLf + "randomSeed(analogRead(0));" + vbCrLf + "}" + vbCrLf + vbCrLf + vbCrLf + "void loop(){" _
                     + vbCrLf + "Animation_" & TextBox4.Text & "();" + vbCrLf + "}" + vbCrLf + vbCrLf + vbCrLf

        code.Text += "void Animation_" & TextBox4.Text & "(){" + vbCrLf

        For a = 1 To Frameanzahl
            FrameNm = "Frame" & a & ".txt"

            Dim fs As New FileStream(FrameNm, FileMode.Open)
            Dim sr As New StreamReader(fs)

            For b = 0 To 26
                images(b) = sr.ReadLine()
            Next
            wiederholungen = sr.ReadLine()

            sr.Close()

            Dim count As Integer
            For c = 0 To 26
                If images(c) = 1 Then
                    count += 1
                End If
            Next

            Dim led_an As Integer
            If count >= 1 Then

                code.Text += "for (int i = 0; i < " & wiederholungen & "; i++){" + vbCrLf

                For i = 0 To 8
                    If images(i) = 1 Then
                        led_an += 1
                    End If
                    If led_an >= 1 Then
                        If images(i) = 1 Then

                            code.Text += "digitalWrite(led[" & i & "],HIGH);" + vbCrLf
                        End If
                        If i = 8 Then
                            code.Text += "digitalWrite(row[0],HIGH);" + vbCrLf + "reset();" + vbCrLf
                        End If
                    Else
                        If i = 8 Then
                            code.Text += "reset();" + vbCrLf
                        End If
                    End If
                Next
                led_an = 0
                For i = 9 To 17
                    If images(i) = 1 Then
                        led_an += 1
                    End If
                    If led_an >= 1 Then
                        If images(i) = 1 Then
                            code.Text += "digitalWrite(led[" & i - 9 & "],HIGH);" + vbCrLf
                        End If
                        If i = 17 Then
                            code.Text += "digitalWrite(row[1],HIGH);" + vbCrLf + "reset();" + vbCrLf
                        End If
                    Else
                        If i = 17 Then
                            code.Text += "reset();" + vbCrLf
                        End If
                    End If
                Next
                led_an = 0
                For i = 18 To 26
                    If images(i) = 1 Then
                        led_an += 1
                    End If
                    If led_an >= 1 Then
                        If images(i) = 1 Then
                            code.Text += "digitalWrite(led[" & i - 18 & "],HIGH);" + vbCrLf
                        End If
                        If i = 26 Then
                            code.Text += "digitalWrite(row[2],HIGH);" + vbCrLf + "clear_all();" + vbCrLf
                        End If
                    Else
                        If i = 26 Then
                            code.Text += "clear_all();" + vbCrLf
                        End If
                    End If

                Next
                led_an = 0
                code.Text += "}" + vbCrLf



            End If
        Next

        code.Text += "}" + vbCrLf + vbCrLf + vbCrLf + vbCrLf

        code.Text += "void reset(){" + vbCrLf + "delayMicroseconds(333);" + vbCrLf + "int pin;" + vbCrLf + "for (pin=0; pin<9; pin++) {" + vbCrLf + "digitalWrite( led[pin], LOW );}" _
                             + vbCrLf + "for (pin=0; pin<3; pin++) {" + vbCrLf + "digitalWrite( row[pin], LOW );}" + vbCrLf + "}" + vbCrLf + vbCrLf
        code.Text += "void clear_all(){" + vbCrLf + "delayMicroseconds(333);" + vbCrLf + "int pin;" + vbCrLf + "for (pin=0; pin<9; pin++) {" + vbCrLf + "digitalWrite( led[pin], LOW );}" _
                             + vbCrLf + "for (pin=0; pin<3; pin++) {" + vbCrLf + "digitalWrite( row[pin], LOW );}" + vbCrLf + "delayMicroseconds(1);" + vbCrLf + "}"

        Dim Dateiname As String = TextBox5.Text

        If System.IO.Directory.Exists("Arduino\Created_Projekts\" + Dateiname + "\") = True Then

            Dim fs3 As New FileStream("Arduino\Created_Projekts\" + Dateiname + "\" + Dateiname + ".ino", FileMode.OpenOrCreate)
            Dim sw3 As New StreamWriter(fs3)

            sw3.WriteLine(code.Text)

            sw3.Close()
        Else
            System.IO.Directory.CreateDirectory("Arduino\Created_Projekts\" + Dateiname + "\")

            Dim fs3 As New FileStream("Arduino\Created_Projekts\" + Dateiname + "\" + Dateiname + ".ino", FileMode.Create)
            Dim sw3 As New StreamWriter(fs3)

            sw3.WriteLine(code.Text)

            sw3.Close()
        End If



    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Clipboard.SetText(code.Text)
    End Sub
End Class
