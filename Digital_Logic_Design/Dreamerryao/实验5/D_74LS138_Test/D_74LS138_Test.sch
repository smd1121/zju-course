<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="SW(5:0)" />
        <signal name="XLXN_6" />
        <signal name="SW(3)" />
        <signal name="SW(4)" />
        <signal name="SW(5)" />
        <signal name="SW(0)" />
        <signal name="SW(1)" />
        <signal name="SW(2)" />
        <signal name="LED(7:0)" />
        <port polarity="Input" name="SW(5:0)" />
        <port polarity="Output" name="LED(7:0)" />
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
        <block symbolname="D_74L138" name="XLXI_2">
            <blockpin signalname="SW(3)" name="G2A" />
            <blockpin signalname="SW(4)" name="G2B" />
            <blockpin signalname="SW(5)" name="G" />
            <blockpin signalname="SW(0)" name="C" />
            <blockpin signalname="SW(1)" name="B" />
            <blockpin signalname="SW(2)" name="A" />
            <blockpin signalname="LED(7:0)" name="Y(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1232" y="1424" name="XLXI_2" orien="R0">
        </instance>
        <iomarker fontsize="28" x="912" y="1488" name="SW(5:0)" orien="R90" />
        <branch name="SW(5:0)">
            <wire x2="912" y1="1008" y2="1040" x1="912" />
            <wire x2="912" y1="1040" y2="1072" x1="912" />
            <wire x2="912" y1="1072" y2="1104" x1="912" />
            <wire x2="912" y1="1104" y2="1136" x1="912" />
            <wire x2="912" y1="1136" y2="1152" x1="912" />
            <wire x2="912" y1="1152" y2="1168" x1="912" />
            <wire x2="912" y1="1168" y2="1200" x1="912" />
            <wire x2="912" y1="1200" y2="1216" x1="912" />
            <wire x2="912" y1="1216" y2="1232" x1="912" />
            <wire x2="912" y1="1232" y2="1264" x1="912" />
            <wire x2="912" y1="1264" y2="1296" x1="912" />
            <wire x2="912" y1="1296" y2="1312" x1="912" />
            <wire x2="912" y1="1312" y2="1328" x1="912" />
            <wire x2="912" y1="1328" y2="1360" x1="912" />
            <wire x2="912" y1="1360" y2="1392" x1="912" />
            <wire x2="912" y1="1392" y2="1408" x1="912" />
            <wire x2="912" y1="1408" y2="1488" x1="912" />
        </branch>
        <bustap x2="1008" y1="1200" y2="1200" x1="912" />
        <bustap x2="1008" y1="1136" y2="1136" x1="912" />
        <bustap x2="1008" y1="1072" y2="1072" x1="912" />
        <bustap x2="1008" y1="1392" y2="1392" x1="912" />
        <bustap x2="1008" y1="1328" y2="1328" x1="912" />
        <bustap x2="1008" y1="1264" y2="1264" x1="912" />
        <branch name="SW(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1020" y="1072" type="branch" />
            <wire x2="1020" y1="1072" y2="1072" x1="1008" />
            <wire x2="1232" y1="1072" y2="1072" x1="1020" />
        </branch>
        <branch name="SW(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1017" y="1136" type="branch" />
            <wire x2="1017" y1="1136" y2="1136" x1="1008" />
            <wire x2="1232" y1="1136" y2="1136" x1="1017" />
        </branch>
        <branch name="SW(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1020" y="1200" type="branch" />
            <wire x2="1020" y1="1200" y2="1200" x1="1008" />
            <wire x2="1232" y1="1200" y2="1200" x1="1020" />
        </branch>
        <branch name="SW(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1023" y="1264" type="branch" />
            <wire x2="1023" y1="1264" y2="1264" x1="1008" />
            <wire x2="1232" y1="1264" y2="1264" x1="1023" />
        </branch>
        <branch name="SW(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1017" y="1328" type="branch" />
            <wire x2="1017" y1="1328" y2="1328" x1="1008" />
            <wire x2="1232" y1="1328" y2="1328" x1="1017" />
        </branch>
        <branch name="SW(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1019" y="1392" type="branch" />
            <wire x2="1019" y1="1392" y2="1392" x1="1008" />
            <wire x2="1232" y1="1392" y2="1392" x1="1019" />
        </branch>
        <branch name="LED(7:0)">
            <wire x2="1888" y1="1072" y2="1072" x1="1616" />
        </branch>
        <iomarker fontsize="28" x="1888" y="1072" name="LED(7:0)" orien="R0" />
    </sheet>
</drawing>