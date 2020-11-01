<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="BTN(1:0)" />
        <signal name="BTN(1)" />
        <signal name="BTN(0)" />
        <signal name="XLXN_5" />
        <signal name="SW(7:0)" />
        <signal name="SW(0)" />
        <signal name="SW(1)" />
        <signal name="SW(2)" />
        <signal name="SW(3)" />
        <signal name="SW(7)" />
        <signal name="SW(6)" />
        <signal name="SW(5)" />
        <signal name="SW(4)" />
        <signal name="AN(3:0)" />
        <signal name="AN(3)" />
        <signal name="AN(2)" />
        <signal name="AN(1)" />
        <signal name="AN(0)" />
        <signal name="SEGMENT(7:0)" />
        <signal name="SEGMENT(7)" />
        <signal name="SEGMENT(6)" />
        <signal name="SEGMENT(5)" />
        <signal name="SEGMENT(4)" />
        <signal name="SEGMENT(3)" />
        <signal name="SEGMENT(2)" />
        <signal name="SEGMENT(1)" />
        <signal name="SEGMENT(0)" />
        <port polarity="Input" name="BTN(1:0)" />
        <port polarity="Input" name="SW(7:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="SEGMENT(7:0)" />
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
        <blockdef name="inv4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="160" y1="-96" y2="-96" x1="224" />
            <line x2="160" y1="-160" y2="-160" x1="224" />
            <line x2="160" y1="-224" y2="-224" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-96" y2="-96" x1="0" />
            <line x2="64" y1="-160" y2="-160" x1="0" />
            <line x2="64" y1="-224" y2="-224" x1="0" />
            <line x2="128" y1="-256" y2="-224" x1="64" />
            <line x2="64" y1="-224" y2="-192" x1="128" />
            <line x2="64" y1="-192" y2="-256" x1="64" />
            <circle r="16" cx="144" cy="-32" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="128" y1="-128" y2="-96" x1="64" />
            <line x2="64" y1="-96" y2="-64" x1="128" />
            <line x2="64" y1="-64" y2="-128" x1="64" />
            <circle r="16" cx="144" cy="-96" />
            <line x2="128" y1="-192" y2="-160" x1="64" />
            <line x2="64" y1="-160" y2="-128" x1="128" />
            <line x2="64" y1="-128" y2="-192" x1="64" />
            <circle r="16" cx="144" cy="-160" />
            <circle r="16" cx="144" cy="-224" />
        </blockdef>
        <block symbolname="MyMC14495" name="XLXI_1">
            <blockpin signalname="BTN(1)" name="point" />
            <blockpin signalname="BTN(0)" name="LE" />
            <blockpin signalname="SW(3)" name="D3" />
            <blockpin signalname="SW(2)" name="D2" />
            <blockpin signalname="SW(1)" name="D1" />
            <blockpin signalname="SW(0)" name="D0" />
            <blockpin signalname="SEGMENT(7)" name="p" />
            <blockpin signalname="SEGMENT(0)" name="a" />
            <blockpin signalname="SEGMENT(1)" name="b" />
            <blockpin signalname="SEGMENT(2)" name="c" />
            <blockpin signalname="SEGMENT(3)" name="d" />
            <blockpin signalname="SEGMENT(4)" name="e" />
            <blockpin signalname="SEGMENT(5)" name="f" />
            <blockpin signalname="SEGMENT(6)" name="g" />
        </block>
        <block symbolname="inv4" name="XLXI_2">
            <blockpin signalname="SW(4)" name="I0" />
            <blockpin signalname="SW(5)" name="I1" />
            <blockpin signalname="SW(6)" name="I2" />
            <blockpin signalname="SW(7)" name="I3" />
            <blockpin signalname="AN(0)" name="O0" />
            <blockpin signalname="AN(1)" name="O1" />
            <blockpin signalname="AN(2)" name="O2" />
            <blockpin signalname="AN(3)" name="O3" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1328" y="1456" name="XLXI_1" orien="R0">
        </instance>
        <branch name="BTN(1:0)">
            <wire x2="624" y1="1120" y2="1120" x1="512" />
            <wire x2="624" y1="1120" y2="1168" x1="624" />
            <wire x2="624" y1="1168" y2="1216" x1="624" />
            <wire x2="624" y1="1024" y2="1072" x1="624" />
            <wire x2="624" y1="1072" y2="1120" x1="624" />
        </branch>
        <iomarker fontsize="28" x="512" y="1120" name="BTN(1:0)" orien="R180" />
        <bustap x2="720" y1="1168" y2="1168" x1="624" />
        <branch name="BTN(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="816" y="960" type="branch" />
            <wire x2="816" y1="1168" y2="1168" x1="720" />
            <wire x2="1040" y1="960" y2="960" x1="816" />
            <wire x2="1040" y1="960" y2="976" x1="1040" />
            <wire x2="1328" y1="976" y2="976" x1="1040" />
            <wire x2="816" y1="960" y2="1168" x1="816" />
        </branch>
        <bustap x2="720" y1="1072" y2="1072" x1="624" />
        <branch name="BTN(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="744" y="1008" type="branch" />
            <wire x2="720" y1="1008" y2="1072" x1="720" />
            <wire x2="744" y1="1008" y2="1008" x1="720" />
            <wire x2="1328" y1="1008" y2="1008" x1="744" />
            <wire x2="1328" y1="1008" y2="1056" x1="1328" />
        </branch>
        <branch name="SW(7:0)">
            <wire x2="912" y1="1632" y2="1632" x1="688" />
            <wire x2="912" y1="1632" y2="1712" x1="912" />
            <wire x2="912" y1="1712" y2="1776" x1="912" />
            <wire x2="912" y1="1776" y2="1808" x1="912" />
            <wire x2="912" y1="1808" y2="1840" x1="912" />
            <wire x2="912" y1="1840" y2="1856" x1="912" />
            <wire x2="912" y1="1856" y2="1904" x1="912" />
            <wire x2="912" y1="1904" y2="1968" x1="912" />
            <wire x2="912" y1="1024" y2="1136" x1="912" />
            <wire x2="912" y1="1136" y2="1216" x1="912" />
            <wire x2="912" y1="1216" y2="1296" x1="912" />
            <wire x2="912" y1="1296" y2="1392" x1="912" />
            <wire x2="912" y1="1392" y2="1632" x1="912" />
        </branch>
        <iomarker fontsize="28" x="688" y="1632" name="SW(7:0)" orien="R180" />
        <branch name="SW(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1024" y="1392" type="branch" />
            <wire x2="1024" y1="1392" y2="1392" x1="1008" />
            <wire x2="1040" y1="1392" y2="1392" x1="1024" />
            <wire x2="1328" y1="1376" y2="1376" x1="1040" />
            <wire x2="1040" y1="1376" y2="1392" x1="1040" />
        </branch>
        <bustap x2="1008" y1="1392" y2="1392" x1="912" />
        <bustap x2="1008" y1="1296" y2="1296" x1="912" />
        <branch name="SW(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1168" y="1296" type="branch" />
            <wire x2="1168" y1="1296" y2="1296" x1="1008" />
            <wire x2="1328" y1="1296" y2="1296" x1="1168" />
        </branch>
        <bustap x2="1008" y1="1216" y2="1216" x1="912" />
        <branch name="SW(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1168" y="1216" type="branch" />
            <wire x2="1168" y1="1216" y2="1216" x1="1008" />
            <wire x2="1328" y1="1216" y2="1216" x1="1168" />
        </branch>
        <bustap x2="1008" y1="1136" y2="1136" x1="912" />
        <branch name="SW(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1168" y="1136" type="branch" />
            <wire x2="1168" y1="1136" y2="1136" x1="1008" />
            <wire x2="1328" y1="1136" y2="1136" x1="1168" />
        </branch>
        <instance x="1232" y="1936" name="XLXI_2" orien="R0" />
        <bustap x2="1008" y1="1712" y2="1712" x1="912" />
        <branch name="SW(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1712" type="branch" />
            <wire x2="1120" y1="1712" y2="1712" x1="1008" />
            <wire x2="1232" y1="1712" y2="1712" x1="1120" />
        </branch>
        <bustap x2="1008" y1="1776" y2="1776" x1="912" />
        <branch name="SW(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1776" type="branch" />
            <wire x2="1120" y1="1776" y2="1776" x1="1008" />
            <wire x2="1232" y1="1776" y2="1776" x1="1120" />
        </branch>
        <bustap x2="1008" y1="1840" y2="1840" x1="912" />
        <branch name="SW(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1840" type="branch" />
            <wire x2="1120" y1="1840" y2="1840" x1="1008" />
            <wire x2="1232" y1="1840" y2="1840" x1="1120" />
        </branch>
        <bustap x2="1008" y1="1904" y2="1904" x1="912" />
        <branch name="SW(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1904" type="branch" />
            <wire x2="1120" y1="1904" y2="1904" x1="1008" />
            <wire x2="1232" y1="1904" y2="1904" x1="1120" />
        </branch>
        <branch name="AN(3:0)">
            <wire x2="2048" y1="1648" y2="1712" x1="2048" />
            <wire x2="2048" y1="1712" y2="1776" x1="2048" />
            <wire x2="2048" y1="1776" y2="1808" x1="2048" />
            <wire x2="2208" y1="1808" y2="1808" x1="2048" />
            <wire x2="2048" y1="1808" y2="1840" x1="2048" />
            <wire x2="2048" y1="1840" y2="1904" x1="2048" />
            <wire x2="2048" y1="1904" y2="1936" x1="2048" />
        </branch>
        <iomarker fontsize="28" x="2208" y="1808" name="AN(3:0)" orien="R0" />
        <bustap x2="1952" y1="1712" y2="1712" x1="2048" />
        <branch name="AN(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1704" y="1712" type="branch" />
            <wire x2="1704" y1="1712" y2="1712" x1="1456" />
            <wire x2="1952" y1="1712" y2="1712" x1="1704" />
        </branch>
        <bustap x2="1952" y1="1776" y2="1776" x1="2048" />
        <branch name="AN(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1704" y="1776" type="branch" />
            <wire x2="1704" y1="1776" y2="1776" x1="1456" />
            <wire x2="1952" y1="1776" y2="1776" x1="1704" />
        </branch>
        <bustap x2="1952" y1="1840" y2="1840" x1="2048" />
        <branch name="AN(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1704" y="1840" type="branch" />
            <wire x2="1704" y1="1840" y2="1840" x1="1456" />
            <wire x2="1952" y1="1840" y2="1840" x1="1704" />
        </branch>
        <bustap x2="1952" y1="1904" y2="1904" x1="2048" />
        <branch name="AN(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1704" y="1904" type="branch" />
            <wire x2="1704" y1="1904" y2="1904" x1="1456" />
            <wire x2="1952" y1="1904" y2="1904" x1="1704" />
        </branch>
        <branch name="SEGMENT(7:0)">
            <wire x2="2016" y1="928" y2="976" x1="2016" />
            <wire x2="2016" y1="976" y2="1040" x1="2016" />
            <wire x2="2016" y1="1040" y2="1104" x1="2016" />
            <wire x2="2016" y1="1104" y2="1152" x1="2016" />
            <wire x2="2160" y1="1152" y2="1152" x1="2016" />
            <wire x2="2016" y1="1152" y2="1168" x1="2016" />
            <wire x2="2016" y1="1168" y2="1232" x1="2016" />
            <wire x2="2016" y1="1232" y2="1296" x1="2016" />
            <wire x2="2016" y1="1296" y2="1360" x1="2016" />
            <wire x2="2016" y1="1360" y2="1424" x1="2016" />
            <wire x2="2016" y1="1424" y2="1440" x1="2016" />
        </branch>
        <iomarker fontsize="28" x="2160" y="1152" name="SEGMENT(7:0)" orien="R0" />
        <bustap x2="1920" y1="976" y2="976" x1="2016" />
        <branch name="SEGMENT(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="976" type="branch" />
            <wire x2="1816" y1="976" y2="976" x1="1712" />
            <wire x2="1920" y1="976" y2="976" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1424" y2="1424" x1="2016" />
        <branch name="SEGMENT(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1424" type="branch" />
            <wire x2="1816" y1="1424" y2="1424" x1="1712" />
            <wire x2="1920" y1="1424" y2="1424" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1360" y2="1360" x1="2016" />
        <branch name="SEGMENT(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1360" type="branch" />
            <wire x2="1816" y1="1360" y2="1360" x1="1712" />
            <wire x2="1920" y1="1360" y2="1360" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1296" y2="1296" x1="2016" />
        <branch name="SEGMENT(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1296" type="branch" />
            <wire x2="1816" y1="1296" y2="1296" x1="1712" />
            <wire x2="1920" y1="1296" y2="1296" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1232" y2="1232" x1="2016" />
        <branch name="SEGMENT(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1232" type="branch" />
            <wire x2="1816" y1="1232" y2="1232" x1="1712" />
            <wire x2="1920" y1="1232" y2="1232" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1168" y2="1168" x1="2016" />
        <branch name="SEGMENT(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1168" type="branch" />
            <wire x2="1816" y1="1168" y2="1168" x1="1712" />
            <wire x2="1920" y1="1168" y2="1168" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1104" y2="1104" x1="2016" />
        <branch name="SEGMENT(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1104" type="branch" />
            <wire x2="1816" y1="1104" y2="1104" x1="1712" />
            <wire x2="1920" y1="1104" y2="1104" x1="1816" />
        </branch>
        <bustap x2="1920" y1="1040" y2="1040" x1="2016" />
        <branch name="SEGMENT(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1816" y="1040" type="branch" />
            <wire x2="1816" y1="1040" y2="1040" x1="1712" />
            <wire x2="1920" y1="1040" y2="1040" x1="1816" />
        </branch>
    </sheet>
</drawing>