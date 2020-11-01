<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="S2" />
        <signal name="S3" />
        <signal name="S1" />
        <signal name="Y(7:0)" />
        <signal name="F" />
        <signal name="Y(7)" />
        <signal name="Y(4)" />
        <signal name="Y(2)" />
        <signal name="Y(1)" />
        <port polarity="Input" name="S2" />
        <port polarity="Input" name="S3" />
        <port polarity="Input" name="S1" />
        <port polarity="Output" name="F" />
        <blockdef name="D_74L138">
            <timestamp>2019-10-13T10:34:20</timestamp>
            <rect width="256" x="64" y="-384" height="384" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-364" height="24" />
            <line x2="384" y1="-352" y2="-352" x1="320" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="nand4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="216" y1="-160" y2="-160" x1="256" />
            <circle r="12" cx="204" cy="-160" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="64" y1="-112" y2="-112" x1="144" />
        </blockdef>
        <block symbolname="D_74L138" name="XLXI_1">
            <blockpin signalname="XLXN_1" name="G2A" />
            <blockpin signalname="XLXN_2" name="G2B" />
            <blockpin signalname="XLXN_3" name="G" />
            <blockpin signalname="S1" name="C" />
            <blockpin signalname="S2" name="B" />
            <blockpin signalname="S3" name="A" />
            <blockpin signalname="Y(7:0)" name="Y(7:0)" />
        </block>
        <block symbolname="gnd" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="G" />
        </block>
        <block symbolname="gnd" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="G" />
        </block>
        <block symbolname="vcc" name="XLXI_4">
            <blockpin signalname="XLXN_3" name="P" />
        </block>
        <block symbolname="nand4" name="NAND4_1">
            <blockpin signalname="Y(7)" name="I0" />
            <blockpin signalname="Y(4)" name="I1" />
            <blockpin signalname="Y(2)" name="I2" />
            <blockpin signalname="Y(1)" name="I3" />
            <blockpin signalname="F" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1440" y="1568" name="XLXI_1" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="1440" y1="1216" y2="1216" x1="1200" />
        </branch>
        <instance x="1136" y="1344" name="XLXI_2" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="1440" y1="1280" y2="1280" x1="1264" />
        </branch>
        <instance x="1200" y="1408" name="XLXI_3" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="800" y1="1344" y2="1360" x1="800" />
            <wire x2="800" y1="1360" y2="1440" x1="800" />
            <wire x2="1344" y1="1440" y2="1440" x1="800" />
            <wire x2="1344" y1="1344" y2="1440" x1="1344" />
            <wire x2="1440" y1="1344" y2="1344" x1="1344" />
        </branch>
        <instance x="736" y="1360" name="XLXI_4" orien="R0" />
        <branch name="S2">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1212" y="1568" type="branch" />
            <wire x2="1212" y1="1568" y2="1568" x1="1104" />
            <wire x2="1264" y1="1568" y2="1568" x1="1212" />
            <wire x2="1264" y1="1472" y2="1568" x1="1264" />
            <wire x2="1440" y1="1472" y2="1472" x1="1264" />
        </branch>
        <branch name="S3">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1213" y="1632" type="branch" />
            <wire x2="1213" y1="1632" y2="1632" x1="1104" />
            <wire x2="1280" y1="1632" y2="1632" x1="1213" />
            <wire x2="1280" y1="1536" y2="1632" x1="1280" />
            <wire x2="1440" y1="1536" y2="1536" x1="1280" />
        </branch>
        <branch name="S1">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1065" y="1488" type="branch" />
            <wire x2="927" y1="1488" y2="1488" x1="896" />
            <wire x2="1048" y1="1488" y2="1488" x1="927" />
            <wire x2="1065" y1="1488" y2="1488" x1="1048" />
            <wire x2="1232" y1="1488" y2="1488" x1="1065" />
            <wire x2="1232" y1="1456" y2="1488" x1="1232" />
            <wire x2="1440" y1="1456" y2="1456" x1="1232" />
            <wire x2="1440" y1="1408" y2="1456" x1="1440" />
        </branch>
        <iomarker fontsize="28" x="896" y="1488" name="S1" orien="R180" />
        <iomarker fontsize="28" x="1104" y="1568" name="S2" orien="R180" />
        <iomarker fontsize="28" x="1104" y="1632" name="S3" orien="R180" />
        <branch name="Y(7:0)">
            <wire x2="1936" y1="1216" y2="1216" x1="1824" />
            <wire x2="1936" y1="1216" y2="1264" x1="1936" />
            <wire x2="1936" y1="1264" y2="1328" x1="1936" />
            <wire x2="1936" y1="1328" y2="1392" x1="1936" />
            <wire x2="1936" y1="1392" y2="1456" x1="1936" />
            <wire x2="1936" y1="1456" y2="1504" x1="1936" />
        </branch>
        <bustap x2="2032" y1="1456" y2="1456" x1="1936" />
        <bustap x2="2032" y1="1392" y2="1392" x1="1936" />
        <bustap x2="2032" y1="1328" y2="1328" x1="1936" />
        <bustap x2="2032" y1="1264" y2="1264" x1="1936" />
        <instance x="2048" y="1520" name="NAND4_1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="-8" type="instance" />
        </instance>
        <branch name="F">
            <wire x2="2336" y1="1360" y2="1360" x1="2304" />
        </branch>
        <iomarker fontsize="28" x="2336" y="1360" name="F" orien="R0" />
        <branch name="Y(7)">
            <wire x2="2048" y1="1456" y2="1456" x1="2032" />
        </branch>
        <branch name="Y(4)">
            <wire x2="2048" y1="1392" y2="1392" x1="2032" />
        </branch>
        <branch name="Y(2)">
            <wire x2="2048" y1="1328" y2="1328" x1="2032" />
        </branch>
        <branch name="Y(1)">
            <wire x2="2048" y1="1264" y2="1264" x1="2032" />
        </branch>
    </sheet>
</drawing>