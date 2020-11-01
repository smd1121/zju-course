<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Y(7:0)" />
        <signal name="Y(0)" />
        <signal name="Y(1)" />
        <signal name="Y(2)" />
        <signal name="Y(4)" />
        <signal name="Y(5)" />
        <signal name="Y(3)" />
        <signal name="Y(6)" />
        <signal name="Y(7)" />
        <signal name="NG" />
        <signal name="G2A" />
        <signal name="G2B" />
        <signal name="G" />
        <signal name="XLXN_17" />
        <signal name="EN" />
        <signal name="C" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="NC" />
        <signal name="XLXN_23" />
        <signal name="D3" />
        <signal name="D2" />
        <signal name="D1" />
        <signal name="D0" />
        <signal name="B" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="NB" />
        <signal name="XLXN_33" />
        <signal name="NA" />
        <signal name="A" />
        <port polarity="Output" name="Y(7:0)" />
        <port polarity="Input" name="G2A" />
        <port polarity="Input" name="G2B" />
        <port polarity="Input" name="G" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="A" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="nor3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="216" y1="-128" y2="-128" x1="256" />
            <circle r="12" cx="204" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
        </blockdef>
        <blockdef name="nand3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="216" y1="-128" y2="-128" x1="256" />
            <circle r="12" cx="204" cy="-128" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <block symbolname="inv" name="INV_A">
            <blockpin signalname="A" name="I" />
            <blockpin signalname="NA" name="O" />
        </block>
        <block symbolname="inv" name="INV_B">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="NB" name="O" />
        </block>
        <block symbolname="and2" name="AND2_1">
            <blockpin signalname="NB" name="I0" />
            <blockpin signalname="NA" name="I1" />
            <blockpin signalname="D0" name="O" />
        </block>
        <block symbolname="and2" name="AND2_2">
            <blockpin signalname="NB" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="D1" name="O" />
        </block>
        <block symbolname="and2" name="AND2_3">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="NA" name="I1" />
            <blockpin signalname="D2" name="O" />
        </block>
        <block symbolname="and2" name="AND2_4">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="D3" name="O" />
        </block>
        <block symbolname="inv" name="INV_C">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="NC" name="O" />
        </block>
        <block symbolname="inv" name="INV_G">
            <blockpin signalname="G" name="I" />
            <blockpin signalname="NG" name="O" />
        </block>
        <block symbolname="nor3" name="nor3_1">
            <blockpin signalname="G2B" name="I0" />
            <blockpin signalname="G2A" name="I1" />
            <blockpin signalname="NG" name="I2" />
            <blockpin signalname="EN" name="O" />
        </block>
        <block symbolname="nand3" name="D_1">
            <blockpin signalname="NC" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D0" name="I2" />
            <blockpin signalname="Y(0)" name="O" />
        </block>
        <block symbolname="nand3" name="D_2">
            <blockpin signalname="NC" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D1" name="I2" />
            <blockpin signalname="Y(1)" name="O" />
        </block>
        <block symbolname="nand3" name="D_3">
            <blockpin signalname="NC" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="Y(2)" name="O" />
        </block>
        <block symbolname="nand3" name="D_4">
            <blockpin signalname="NC" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D3" name="I2" />
            <blockpin signalname="Y(3)" name="O" />
        </block>
        <block symbolname="nand3" name="D_5">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D0" name="I2" />
            <blockpin signalname="Y(4)" name="O" />
        </block>
        <block symbolname="nand3" name="D_7">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="Y(6)" name="O" />
        </block>
        <block symbolname="nand3" name="D_8">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D3" name="I2" />
            <blockpin signalname="Y(7)" name="O" />
        </block>
        <block symbolname="nand3" name="D_6">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="EN" name="I1" />
            <blockpin signalname="D1" name="I2" />
            <blockpin signalname="Y(5)" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="976" y="608" name="INV_A" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="24" type="instance" />
        </instance>
        <instance x="976" y="944" name="INV_B" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="24" type="instance" />
        </instance>
        <instance x="1536" y="624" name="AND2_1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="1536" y="912" name="AND2_2" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="1536" y="1184" name="AND2_3" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="1536" y="1488" name="AND2_4" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="736" y="2304" name="INV_G" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="24" type="instance" />
        </instance>
        <instance x="1232" y="2560" name="nor3_1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="656" name="D_1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="944" name="D_2" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="1216" name="D_3" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="1488" name="D_4" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="1760" name="D_5" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2272" y="2320" name="D_7" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <instance x="2288" y="2592" name="D_8" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <branch name="Y(7:0)">
            <wire x2="3200" y1="752" y2="864" x1="3200" />
            <wire x2="3200" y1="864" y2="976" x1="3200" />
            <wire x2="3200" y1="976" y2="1104" x1="3200" />
            <wire x2="3200" y1="1104" y2="1248" x1="3200" />
            <wire x2="3200" y1="1248" y2="1399" x1="3200" />
            <wire x2="3200" y1="1399" y2="1440" x1="3200" />
            <wire x2="3200" y1="1440" y2="1488" x1="3200" />
            <wire x2="3296" y1="1488" y2="1488" x1="3200" />
            <wire x2="3200" y1="1488" y2="1648" x1="3200" />
            <wire x2="3200" y1="1648" y2="1888" x1="3200" />
            <wire x2="3200" y1="1888" y2="2080" x1="3200" />
            <wire x2="3200" y1="2080" y2="2208" x1="3200" />
        </branch>
        <iomarker fontsize="28" x="3296" y="1488" name="Y(7:0)" orien="R0" />
        <bustap x2="3104" y1="864" y2="864" x1="3200" />
        <bustap x2="3104" y1="976" y2="976" x1="3200" />
        <bustap x2="3104" y1="1104" y2="1104" x1="3200" />
        <bustap x2="3104" y1="1248" y2="1248" x1="3200" />
        <bustap x2="3104" y1="1440" y2="1440" x1="3200" />
        <bustap x2="3104" y1="1648" y2="1648" x1="3200" />
        <bustap x2="3104" y1="1888" y2="1888" x1="3200" />
        <bustap x2="3104" y1="2080" y2="2080" x1="3200" />
        <branch name="Y(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3082" y="864" type="branch" />
            <wire x2="2816" y1="528" y2="528" x1="2528" />
            <wire x2="2816" y1="528" y2="864" x1="2816" />
            <wire x2="2903" y1="864" y2="864" x1="2816" />
            <wire x2="3012" y1="864" y2="864" x1="2903" />
            <wire x2="3082" y1="864" y2="864" x1="3012" />
            <wire x2="3104" y1="864" y2="864" x1="3082" />
        </branch>
        <branch name="Y(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3092" y="976" type="branch" />
            <wire x2="2800" y1="816" y2="816" x1="2528" />
            <wire x2="2800" y1="816" y2="976" x1="2800" />
            <wire x2="3092" y1="976" y2="976" x1="2800" />
            <wire x2="3104" y1="976" y2="976" x1="3092" />
        </branch>
        <branch name="Y(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3086" y="1104" type="branch" />
            <wire x2="2816" y1="1088" y2="1088" x1="2528" />
            <wire x2="2816" y1="1088" y2="1104" x1="2816" />
            <wire x2="3086" y1="1104" y2="1104" x1="2816" />
            <wire x2="3104" y1="1104" y2="1104" x1="3086" />
        </branch>
        <branch name="Y(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3079" y="1440" type="branch" />
            <wire x2="2816" y1="1632" y2="1632" x1="2528" />
            <wire x2="2816" y1="1440" y2="1632" x1="2816" />
            <wire x2="3068" y1="1440" y2="1440" x1="2816" />
            <wire x2="3079" y1="1440" y2="1440" x1="3068" />
            <wire x2="3104" y1="1440" y2="1440" x1="3079" />
        </branch>
        <branch name="Y(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3089" y="1648" type="branch" />
            <wire x2="2816" y1="1904" y2="1904" x1="2544" />
            <wire x2="2816" y1="1648" y2="1904" x1="2816" />
            <wire x2="3089" y1="1648" y2="1648" x1="2816" />
            <wire x2="3104" y1="1648" y2="1648" x1="3089" />
        </branch>
        <branch name="Y(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3082" y="1248" type="branch" />
            <wire x2="2816" y1="1360" y2="1360" x1="2528" />
            <wire x2="2816" y1="1248" y2="1360" x1="2816" />
            <wire x2="3082" y1="1248" y2="1248" x1="2816" />
            <wire x2="3104" y1="1248" y2="1248" x1="3082" />
        </branch>
        <branch name="Y(6)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3104" y="1913" type="branch" />
            <wire x2="2832" y1="2192" y2="2192" x1="2528" />
            <wire x2="2832" y1="1936" y2="2192" x1="2832" />
            <wire x2="3104" y1="1936" y2="1936" x1="2832" />
            <wire x2="3104" y1="1888" y2="1913" x1="3104" />
            <wire x2="3104" y1="1913" y2="1936" x1="3104" />
        </branch>
        <branch name="Y(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3093" y="2080" type="branch" />
            <wire x2="2848" y1="2464" y2="2464" x1="2544" />
            <wire x2="2848" y1="2080" y2="2464" x1="2848" />
            <wire x2="3093" y1="2080" y2="2080" x1="2848" />
            <wire x2="3104" y1="2080" y2="2080" x1="3093" />
        </branch>
        <branch name="NG">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1169" y="2272" type="branch" />
            <wire x2="1169" y1="2272" y2="2272" x1="960" />
            <wire x2="1232" y1="2272" y2="2272" x1="1169" />
            <wire x2="1232" y1="2272" y2="2368" x1="1232" />
        </branch>
        <branch name="G2A">
            <wire x2="1232" y1="2432" y2="2432" x1="448" />
        </branch>
        <branch name="G2B">
            <wire x2="1232" y1="2496" y2="2496" x1="448" />
        </branch>
        <iomarker fontsize="28" x="448" y="2432" name="G2A" orien="R180" />
        <iomarker fontsize="28" x="448" y="2496" name="G2B" orien="R180" />
        <branch name="G">
            <wire x2="736" y1="2272" y2="2272" x1="400" />
        </branch>
        <iomarker fontsize="28" x="400" y="2272" name="G" orien="R180" />
        <branch name="EN">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1787" y="2432" type="branch" />
            <wire x2="1787" y1="2432" y2="2432" x1="1488" />
            <wire x2="1888" y1="2432" y2="2432" x1="1787" />
            <wire x2="1888" y1="2432" y2="2464" x1="1888" />
            <wire x2="2208" y1="2464" y2="2464" x1="1888" />
            <wire x2="2288" y1="2464" y2="2464" x1="2208" />
            <wire x2="2272" y1="528" y2="528" x1="2208" />
            <wire x2="2208" y1="528" y2="816" x1="2208" />
            <wire x2="2208" y1="816" y2="1088" x1="2208" />
            <wire x2="2208" y1="1088" y2="1360" x1="2208" />
            <wire x2="2208" y1="1360" y2="1632" x1="2208" />
            <wire x2="2208" y1="1632" y2="1904" x1="2208" />
            <wire x2="2208" y1="1904" y2="2192" x1="2208" />
            <wire x2="2208" y1="2192" y2="2464" x1="2208" />
            <wire x2="2272" y1="2192" y2="2192" x1="2208" />
            <wire x2="2288" y1="1904" y2="1904" x1="2208" />
            <wire x2="2272" y1="1632" y2="1632" x1="2208" />
            <wire x2="2272" y1="1360" y2="1360" x1="2208" />
            <wire x2="2272" y1="1088" y2="1088" x1="2208" />
            <wire x2="2272" y1="816" y2="816" x1="2208" />
        </branch>
        <branch name="C">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1761" y="1696" type="branch" />
            <wire x2="1088" y1="1696" y2="1696" x1="416" />
            <wire x2="1761" y1="1696" y2="1696" x1="1088" />
            <wire x2="2016" y1="1696" y2="1696" x1="1761" />
            <wire x2="2272" y1="1696" y2="1696" x1="2016" />
            <wire x2="2016" y1="1696" y2="1968" x1="2016" />
            <wire x2="2016" y1="1968" y2="2256" x1="2016" />
            <wire x2="2016" y1="2256" y2="2528" x1="2016" />
            <wire x2="2288" y1="2528" y2="2528" x1="2016" />
            <wire x2="2272" y1="2256" y2="2256" x1="2016" />
            <wire x2="2288" y1="1968" y2="1968" x1="2016" />
            <wire x2="1552" y1="1616" y2="1616" x1="1088" />
            <wire x2="1088" y1="1616" y2="1696" x1="1088" />
        </branch>
        <iomarker fontsize="28" x="416" y="1696" name="C" orien="R180" />
        <instance x="1552" y="1648" name="INV_C" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="24" type="instance" />
        </instance>
        <branch name="NC">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1920" y="1616" type="branch" />
            <wire x2="1920" y1="1616" y2="1616" x1="1776" />
            <wire x2="1930" y1="1616" y2="1616" x1="1920" />
            <wire x2="2016" y1="1616" y2="1616" x1="1930" />
            <wire x2="2272" y1="592" y2="592" x1="2016" />
            <wire x2="2016" y1="592" y2="880" x1="2016" />
            <wire x2="2272" y1="880" y2="880" x1="2016" />
            <wire x2="2016" y1="880" y2="1152" x1="2016" />
            <wire x2="2272" y1="1152" y2="1152" x1="2016" />
            <wire x2="2016" y1="1152" y2="1424" x1="2016" />
            <wire x2="2016" y1="1424" y2="1616" x1="2016" />
            <wire x2="2272" y1="1424" y2="1424" x1="2016" />
        </branch>
        <instance x="2288" y="2032" name="D_6" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <branch name="D3">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1877" y="1392" type="branch" />
            <wire x2="1877" y1="1392" y2="1392" x1="1792" />
            <wire x2="1984" y1="1392" y2="1392" x1="1877" />
            <wire x2="1984" y1="1392" y2="2320" x1="1984" />
            <wire x2="2288" y1="2320" y2="2320" x1="1984" />
            <wire x2="2288" y1="2320" y2="2400" x1="2288" />
            <wire x2="2272" y1="1296" y2="1296" x1="1984" />
            <wire x2="1984" y1="1296" y2="1392" x1="1984" />
        </branch>
        <branch name="D2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1864" y="1088" type="branch" />
            <wire x2="1864" y1="1088" y2="1088" x1="1792" />
            <wire x2="1968" y1="1088" y2="1088" x1="1864" />
            <wire x2="1968" y1="1088" y2="2128" x1="1968" />
            <wire x2="2272" y1="2128" y2="2128" x1="1968" />
            <wire x2="2272" y1="1024" y2="1024" x1="1968" />
            <wire x2="1968" y1="1024" y2="1088" x1="1968" />
        </branch>
        <branch name="D1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1869" y="816" type="branch" />
            <wire x2="1869" y1="816" y2="816" x1="1792" />
            <wire x2="1952" y1="816" y2="816" x1="1869" />
            <wire x2="1952" y1="816" y2="1760" x1="1952" />
            <wire x2="2288" y1="1760" y2="1760" x1="1952" />
            <wire x2="2288" y1="1760" y2="1840" x1="2288" />
            <wire x2="2272" y1="752" y2="752" x1="1952" />
            <wire x2="1952" y1="752" y2="816" x1="1952" />
        </branch>
        <branch name="D0">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1866" y="528" type="branch" />
            <wire x2="1866" y1="528" y2="528" x1="1792" />
            <wire x2="1936" y1="528" y2="528" x1="1866" />
            <wire x2="1936" y1="528" y2="1568" x1="1936" />
            <wire x2="2272" y1="1568" y2="1568" x1="1936" />
            <wire x2="2272" y1="464" y2="464" x1="1936" />
            <wire x2="1936" y1="464" y2="528" x1="1936" />
        </branch>
        <branch name="B">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1487" y="1424" type="branch" />
            <wire x2="720" y1="1056" y2="1056" x1="320" />
            <wire x2="1408" y1="1056" y2="1056" x1="720" />
            <wire x2="1408" y1="1056" y2="1120" x1="1408" />
            <wire x2="1408" y1="1120" y2="1424" x1="1408" />
            <wire x2="1487" y1="1424" y2="1424" x1="1408" />
            <wire x2="1536" y1="1424" y2="1424" x1="1487" />
            <wire x2="1536" y1="1120" y2="1120" x1="1408" />
            <wire x2="976" y1="912" y2="912" x1="720" />
            <wire x2="720" y1="912" y2="1056" x1="720" />
        </branch>
        <iomarker fontsize="28" x="320" y="1056" name="B" orien="R180" />
        <branch name="NB">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1352" y="912" type="branch" />
            <wire x2="1352" y1="912" y2="912" x1="1200" />
            <wire x2="1372" y1="912" y2="912" x1="1352" />
            <wire x2="1472" y1="912" y2="912" x1="1372" />
            <wire x2="1536" y1="560" y2="560" x1="1472" />
            <wire x2="1472" y1="560" y2="848" x1="1472" />
            <wire x2="1472" y1="848" y2="912" x1="1472" />
            <wire x2="1536" y1="848" y2="848" x1="1472" />
        </branch>
        <branch name="NA">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1474" y="496" type="branch" />
            <wire x2="1312" y1="576" y2="576" x1="1200" />
            <wire x2="1312" y1="576" y2="592" x1="1312" />
            <wire x2="1424" y1="592" y2="592" x1="1312" />
            <wire x2="1424" y1="592" y2="1056" x1="1424" />
            <wire x2="1536" y1="1056" y2="1056" x1="1424" />
            <wire x2="1424" y1="496" y2="592" x1="1424" />
            <wire x2="1474" y1="496" y2="496" x1="1424" />
            <wire x2="1536" y1="496" y2="496" x1="1474" />
        </branch>
        <branch name="A">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1462" y="1360" type="branch" />
            <wire x2="672" y1="640" y2="640" x1="288" />
            <wire x2="1312" y1="640" y2="640" x1="672" />
            <wire x2="1312" y1="640" y2="784" x1="1312" />
            <wire x2="1312" y1="784" y2="1360" x1="1312" />
            <wire x2="1462" y1="1360" y2="1360" x1="1312" />
            <wire x2="1536" y1="1360" y2="1360" x1="1462" />
            <wire x2="1536" y1="784" y2="784" x1="1312" />
            <wire x2="976" y1="576" y2="576" x1="672" />
            <wire x2="672" y1="576" y2="640" x1="672" />
        </branch>
        <iomarker fontsize="28" x="288" y="640" name="A" orien="R180" />
    </sheet>
</drawing>