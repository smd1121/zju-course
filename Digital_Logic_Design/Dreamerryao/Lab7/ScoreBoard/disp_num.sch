<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="clk" />
        <signal name="RST" />
        <signal name="clkd(31:0)" />
        <signal name="clkd(18:17)" />
        <signal name="HEXS(15:0)" />
        <signal name="points(3:0)" />
        <signal name="LES(3:0)" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="HEX(3:0)" />
        <signal name="HEX(3)" />
        <signal name="HEX(2)" />
        <signal name="HEX(1)" />
        <signal name="HEX(0)" />
        <signal name="AN(3:0)" />
        <signal name="Segment(7:0)" />
        <signal name="Segment(7)" />
        <signal name="Segment(6)" />
        <signal name="Segment(5)" />
        <signal name="Segment(4)" />
        <signal name="Segment(3)" />
        <signal name="Segment(2)" />
        <signal name="Segment(1)" />
        <signal name="Segment(0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Input" name="RST" />
        <port polarity="Input" name="HEXS(15:0)" />
        <port polarity="Input" name="points(3:0)" />
        <port polarity="Input" name="LES(3:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="Segment(7:0)" />
        <blockdef name="clkdiv">
            <timestamp>2019-10-30T8:44:50</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="MyMC14495">
            <timestamp>2019-10-23T10:10:10</timestamp>
            <rect width="256" x="64" y="-512" height="512" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <line x2="0" y1="-400" y2="-400" x1="64" />
            <line x2="0" y1="-320" y2="-320" x1="64" />
            <line x2="0" y1="-240" y2="-240" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-80" y2="-80" x1="64" />
            <line x2="384" y1="-480" y2="-480" x1="320" />
            <line x2="384" y1="-416" y2="-416" x1="320" />
            <line x2="384" y1="-352" y2="-352" x1="320" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="DisplaySync">
            <timestamp>2019-10-30T9:12:54</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="clkdiv" name="XLXI_1">
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="RST" name="rst" />
            <blockpin signalname="clkd(31:0)" name="clkdiv(31:0)" />
        </block>
        <block symbolname="MyMC14495" name="XLXI_2">
            <blockpin signalname="XLXN_8" name="point" />
            <blockpin signalname="XLXN_9" name="LE" />
            <blockpin signalname="HEX(3)" name="D3" />
            <blockpin signalname="HEX(2)" name="D2" />
            <blockpin signalname="HEX(1)" name="D1" />
            <blockpin signalname="HEX(0)" name="D0" />
            <blockpin signalname="Segment(7)" name="p" />
            <blockpin signalname="Segment(0)" name="a" />
            <blockpin signalname="Segment(1)" name="b" />
            <blockpin signalname="Segment(2)" name="c" />
            <blockpin signalname="Segment(3)" name="d" />
            <blockpin signalname="Segment(4)" name="e" />
            <blockpin signalname="Segment(5)" name="f" />
            <blockpin signalname="Segment(6)" name="g" />
        </block>
        <block symbolname="DisplaySync" name="XLXI_4">
            <blockpin signalname="clkd(18:17)" name="Scan(1:0)" />
            <blockpin signalname="HEXS(15:0)" name="Hexs(15:0)" />
            <blockpin signalname="points(3:0)" name="point(3:0)" />
            <blockpin signalname="LES(3:0)" name="LES(3:0)" />
            <blockpin signalname="HEX(3:0)" name="HEX(3:0)" />
            <blockpin signalname="XLXN_8" name="p" />
            <blockpin signalname="XLXN_9" name="LE" />
            <blockpin signalname="AN(3:0)" name="AN(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="912" y="1312" name="XLXI_1" orien="R0">
        </instance>
        <instance x="2144" y="1296" name="XLXI_2" orien="R0">
        </instance>
        <branch name="clk">
            <wire x2="912" y1="1216" y2="1216" x1="592" />
        </branch>
        <branch name="RST">
            <wire x2="912" y1="1280" y2="1280" x1="592" />
        </branch>
        <iomarker fontsize="28" x="592" y="1216" name="clk" orien="R180" />
        <iomarker fontsize="28" x="592" y="1280" name="RST" orien="R180" />
        <branch name="clkd(31:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1326" y="1216" type="branch" />
            <wire x2="1328" y1="1216" y2="1216" x1="1296" />
            <wire x2="1360" y1="1216" y2="1216" x1="1328" />
            <wire x2="1360" y1="1216" y2="1824" x1="1360" />
            <wire x2="1360" y1="1824" y2="1840" x1="1360" />
        </branch>
        <bustap x2="1456" y1="1824" y2="1824" x1="1360" />
        <branch name="clkd(18:17)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1464" y="1824" type="branch" />
            <wire x2="1472" y1="1824" y2="1824" x1="1456" />
        </branch>
        <branch name="HEXS(15:0)">
            <wire x2="1472" y1="1888" y2="1888" x1="1072" />
        </branch>
        <branch name="points(3:0)">
            <wire x2="1472" y1="1952" y2="1952" x1="1056" />
        </branch>
        <branch name="LES(3:0)">
            <wire x2="1472" y1="2016" y2="2016" x1="1056" />
        </branch>
        <iomarker fontsize="28" x="1072" y="1888" name="HEXS(15:0)" orien="R180" />
        <iomarker fontsize="28" x="1056" y="1952" name="points(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1056" y="2016" name="LES(3:0)" orien="R180" />
        <branch name="XLXN_9">
            <wire x2="2128" y1="1952" y2="1952" x1="1856" />
            <wire x2="2144" y1="896" y2="896" x1="2128" />
            <wire x2="2128" y1="896" y2="1952" x1="2128" />
        </branch>
        <branch name="HEX(3:0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1924" y="1824" type="branch" />
            <wire x2="1968" y1="1824" y2="1824" x1="1856" />
            <wire x2="1968" y1="944" y2="976" x1="1968" />
            <wire x2="1968" y1="976" y2="1056" x1="1968" />
            <wire x2="1968" y1="1056" y2="1136" x1="1968" />
            <wire x2="1968" y1="1136" y2="1216" x1="1968" />
            <wire x2="1968" y1="1216" y2="1824" x1="1968" />
        </branch>
        <bustap x2="2064" y1="976" y2="976" x1="1968" />
        <branch name="HEX(3)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2104" y="976" type="branch" />
            <wire x2="2112" y1="976" y2="976" x1="2064" />
            <wire x2="2144" y1="976" y2="976" x1="2112" />
        </branch>
        <bustap x2="2064" y1="1056" y2="1056" x1="1968" />
        <branch name="HEX(2)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2104" y="1056" type="branch" />
            <wire x2="2112" y1="1056" y2="1056" x1="2064" />
            <wire x2="2144" y1="1056" y2="1056" x1="2112" />
        </branch>
        <bustap x2="2064" y1="1136" y2="1136" x1="1968" />
        <branch name="HEX(1)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2104" y="1136" type="branch" />
            <wire x2="2112" y1="1136" y2="1136" x1="2064" />
            <wire x2="2144" y1="1136" y2="1136" x1="2112" />
        </branch>
        <bustap x2="2064" y1="1216" y2="1216" x1="1968" />
        <branch name="HEX(0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2104" y="1216" type="branch" />
            <wire x2="2112" y1="1216" y2="1216" x1="2064" />
            <wire x2="2144" y1="1216" y2="1216" x1="2112" />
        </branch>
        <branch name="AN(3:0)">
            <wire x2="2336" y1="2016" y2="2016" x1="1856" />
        </branch>
        <iomarker fontsize="28" x="2336" y="2016" name="AN(3:0)" orien="R0" />
        <branch name="Segment(7:0)">
            <wire x2="2832" y1="784" y2="816" x1="2832" />
            <wire x2="2832" y1="816" y2="880" x1="2832" />
            <wire x2="2832" y1="880" y2="944" x1="2832" />
            <wire x2="2832" y1="944" y2="1008" x1="2832" />
            <wire x2="2832" y1="1008" y2="1072" x1="2832" />
            <wire x2="2832" y1="1072" y2="1136" x1="2832" />
            <wire x2="2832" y1="1136" y2="1184" x1="2832" />
            <wire x2="3088" y1="1184" y2="1184" x1="2832" />
            <wire x2="2832" y1="1184" y2="1200" x1="2832" />
            <wire x2="2832" y1="1200" y2="1264" x1="2832" />
            <wire x2="2832" y1="1264" y2="1312" x1="2832" />
        </branch>
        <iomarker fontsize="28" x="3088" y="1184" name="Segment(7:0)" orien="R0" />
        <bustap x2="2736" y1="816" y2="816" x1="2832" />
        <branch name="Segment(7)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="816" type="branch" />
            <wire x2="2640" y1="816" y2="816" x1="2528" />
            <wire x2="2736" y1="816" y2="816" x1="2640" />
        </branch>
        <bustap x2="2736" y1="1264" y2="1264" x1="2832" />
        <branch name="Segment(6)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="1264" type="branch" />
            <wire x2="2640" y1="1264" y2="1264" x1="2528" />
            <wire x2="2736" y1="1264" y2="1264" x1="2640" />
        </branch>
        <bustap x2="2736" y1="1200" y2="1200" x1="2832" />
        <branch name="Segment(5)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="1200" type="branch" />
            <wire x2="2640" y1="1200" y2="1200" x1="2528" />
            <wire x2="2736" y1="1200" y2="1200" x1="2640" />
        </branch>
        <bustap x2="2736" y1="1136" y2="1136" x1="2832" />
        <branch name="Segment(4)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="1136" type="branch" />
            <wire x2="2640" y1="1136" y2="1136" x1="2528" />
            <wire x2="2736" y1="1136" y2="1136" x1="2640" />
        </branch>
        <bustap x2="2736" y1="1072" y2="1072" x1="2832" />
        <branch name="Segment(3)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="1072" type="branch" />
            <wire x2="2640" y1="1072" y2="1072" x1="2528" />
            <wire x2="2736" y1="1072" y2="1072" x1="2640" />
        </branch>
        <bustap x2="2736" y1="1008" y2="1008" x1="2832" />
        <branch name="Segment(2)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="1008" type="branch" />
            <wire x2="2640" y1="1008" y2="1008" x1="2528" />
            <wire x2="2736" y1="1008" y2="1008" x1="2640" />
        </branch>
        <bustap x2="2736" y1="944" y2="944" x1="2832" />
        <branch name="Segment(1)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="944" type="branch" />
            <wire x2="2640" y1="944" y2="944" x1="2528" />
            <wire x2="2736" y1="944" y2="944" x1="2640" />
        </branch>
        <bustap x2="2736" y1="880" y2="880" x1="2832" />
        <branch name="Segment(0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2632" y="880" type="branch" />
            <wire x2="2640" y1="880" y2="880" x1="2528" />
            <wire x2="2736" y1="880" y2="880" x1="2640" />
        </branch>
        <instance x="1472" y="2048" name="XLXI_4" orien="R0">
        </instance>
        <branch name="XLXN_8">
            <wire x2="1952" y1="1888" y2="1888" x1="1856" />
            <wire x2="1952" y1="816" y2="1888" x1="1952" />
            <wire x2="2144" y1="816" y2="816" x1="1952" />
        </branch>
    </sheet>
</drawing>