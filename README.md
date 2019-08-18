# EnumInputProcessorProfile

Enumerate [TF_INPUTPROCESSORPROFILE](https://docs.microsoft.com/en-us/windows/win32/api/msctf/ns-msctf-tf_inputprocessorprofile).

Run:

```bat
EnumInputProcessorProfile
```

Output:

```
          +------- D: TF_IPP_CAPS_DISABLEONTRANSITORY
          |+------ S: TF_IPP_CAPS_SECUREMODESUPPORT
          ||+----- U: TF_IPP_CAPS_UIELEMENTENABLED
          |||+---- L: TF_IPP_CAPS_COMLESSSUPPORT
          ||||+--- W: TF_IPP_CAPS_WOW16SUPPORT
          |||||+-- I: TF_IPP_CAPS_IMMERSIVESUPPORT
          ||||||+- T: TF_IPP_CAPS_SYSTRAYSUPPORT
          |||||||
          |||||||            +--- A: TF_IPP_FLAG_ACTIVE
          |||||||            |+-- E: TF_IPP_FLAG_ENABLED
          |||||||            ||+- S: TF_IPP_FLAG_SUBSTITUTEDBYINPUTPROCESSOR
          |||||||            |||
00000000 <.......> 00000000 <...> KBD CLSID {00000000-0000-0000-0000-000000000000} ""
8003002E <.SUL.IT> 00000003 <AE.> TIP CLSID {03B5835F-F03C-411B-9CE2-AA23E1171E36} "IMJPTIP"
0003003E <.SULWIT> 00000002 <.E.> TIP CLSID {B166439D-B0E1-4F24-BA36-E88CAA865815} "ATOK 2016"
0003000E <.SUL.IT> 00000002 <.E.> TIP CLSID {C0DEDEC0-0000-0000-0000-534B4B464550} "SKKFEP"
0003002C <..UL.IT> 00000002 <.E.> TIP CLSID {D5A86FD5-5308-47EA-AD16-9C4EB160EC3C} "Google Japanese Input"
00000000 <.......> 00000002 <.E.> TIP CLSID {D35F0E50-63E9-4BD4-A76A-F4AAEBA03415} "WinAnthy"
0003002E <.SUL.IT> 00000002 <.E.> TIP CLSID {FA3CBCCE-F4A6-4C08-9712-23FE8F0CD9D4} "Japanist 10"
0003002E <.SUL.IT> 00000002 <.E.> TIP CLSID {EAEA0E29-AA1E-48EF-B2DF-46F4E24C6265} "CorvusSKK"
00000000 <.......> 00000000 <...> KBD CLSID {00000000-0000-0000-0000-000000000000} ""
9003002E <.SUL.IT> 00000000 <...> TIP CLSID {6A498709-E00B-4C45-A018-8F9E4081AE40} ""
9003002E <.SUL.IT> 00000002 <.E.> TIP CLSID {81D4E9C9-1D3B-41BC-9E6C-4B40BF79E35E} ""
00000000 <.......> 00000002 <.E.> KBD CLSID {00000000-0000-0000-0000-000000000000} ""
00000000 <.......> 00000002 <.E.> TIP CLSID {23E97BC9-F2D3-4B25-8EF3-D78391BF2150} "Mark Text Service"
00000000 <.......> 00000002 <.E.> TIP CLSID {6565D455-5030-4C0F-8871-83F6AFDE514F} "Case Text Service"
00000000 <.......> 00000002 <.E.> TIP CLSID {B91867DE-046B-4725-B9C4-D5FE1F489A62} "Microsoft Indic Language Input Tool"
00000000 <.......> 00000000 <...> KBD CLSID {00000000-0000-0000-0000-000000000000} ""
00000000 <.......> 00000002 <.E.> KBD CLSID {00000000-0000-0000-0000-000000000000} ""
9003002E <.SUL.IT> 00000000 <...> TIP CLSID {531FDEBF-9B4C-4A43-A2AA-960E8FCDC732} ""
9003002E <.SUL.IT> 00000000 <...> TIP CLSID {531FDEBF-9B4C-4A43-A2AA-960E8FCDC732} ""
8003002E <.SUL.IT> 00000000 <...> TIP CLSID {B115690A-EA02-48D5-A231-E3578D2FDF80} ""
0003001E <.SULWIT> 00000000 <...> TIP CLSID {E429B25A-E5D3-4D1F-9BE3-0C608477E3A1} "Table Driven Text Input Processor"
0003001E <.SULWIT> 00000000 <...> TIP CLSID {E429B25A-E5D3-4D1F-9BE3-0C608477E3A1} "Table Driven Text Input Processor"
40030000 <.....IT> 00000000 <...> TIP CLSID {7C472071-36A7-4709-88CC-859513E583A9} ""
00000004 <..U....> 00000003 <AE.> TIP CLSID {8613E14C-D0C0-4161-AC0F-1DD2563286BC} "Correction Widget Class"
00000004 <..U....> 00000000 <...> TIP CLSID {F25E9F57-2FC8-4EB3-A41A-CCE5F08541E6} "CPenIMX Class"
00000000 <.......> 00000000 <...> TIP CLSID {FA445657-9379-11D6-B41A-00065B83EE53} ""
00000000 <.......> 00000000 <...> TIP CLSID {DCBD6FA8-032F-11D3-B5B1-00C04FC324A1} "speechtextservice class"
8003002E <.SUL.IT> 00000000 <...> TIP CLSID {A028AE76-01B1-46C2-99C4-ACD9858AE02F} "IMKRTIP"
00030000 <.....IT> 00000000 <...> TIP CLSID {A1E2B86B-924A-4D43-80F6-8A820DF7190F} "IMKROTIP"
0003001E <.SULWIT> 00000000 <...> TIP CLSID {E429B25A-E5D3-4D1F-9BE3-0C608477E3A1} "Table Driven Text Input Processor"
0003001E <.SULWIT> 00000000 <...> TIP CLSID {E429B25A-E5D3-4D1F-9BE3-0C608477E3A1} "Table Driven Text Input Processor"
```