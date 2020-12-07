<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="S2" />
        <signal name="S1" />
        <signal name="G" />
        <signal name="G2A" />
        <signal name="G2B" />
        <signal name="S3" />
        <signal name="Y(7:0)" />
        <signal name="Y(7)" />
        <signal name="Y(1)" />
        <signal name="Y(2)" />
        <signal name="Y(4)" />
        <signal name="F" />
        <port polarity="Input" name="S2" />
        <port polarity="Input" name="S1" />
        <port polarity="Input" name="G" />
        <port polarity="Input" name="G2A" />
        <port polarity="Input" name="G2B" />
        <port polarity="Input" name="S3" />
        <port polarity="Output" name="F" />
        <blockdef name="D_74LS138">
            <timestamp>2020-10-19T9:13:44</timestamp>
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
        <block symbolname="nand4" name="XLXI_3">
            <blockpin signalname="Y(4)" name="I0" />
            <blockpin signalname="Y(2)" name="I1" />
            <blockpin signalname="Y(1)" name="I2" />
            <blockpin signalname="Y(7)" name="I3" />
            <blockpin signalname="F" name="O" />
        </block>
        <block symbolname="D_74LS138" name="XLXI_6">
            <blockpin signalname="S2" name="B" />
            <blockpin signalname="S1" name="A" />
            <blockpin signalname="G" name="G" />
            <blockpin signalname="G2A" name="G2A" />
            <blockpin signalname="G2B" name="G2B" />
            <blockpin signalname="S3" name="C" />
            <blockpin signalname="Y(7:0)" name="Y(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="S2">
            <wire x2="1456" y1="864" y2="864" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="864" name="S2" orien="R180" />
        <branch name="S1">
            <wire x2="1456" y1="928" y2="928" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="928" name="S1" orien="R180" />
        <branch name="G">
            <wire x2="1456" y1="992" y2="992" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="992" name="G" orien="R180" />
        <branch name="G2A">
            <wire x2="1456" y1="1056" y2="1056" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="1056" name="G2A" orien="R180" />
        <branch name="G2B">
            <wire x2="1456" y1="1120" y2="1120" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="1120" name="G2B" orien="R180" />
        <branch name="S3">
            <wire x2="1456" y1="1184" y2="1184" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1408" y="1184" name="S3" orien="R180" />
        <branch name="Y(7:0)">
            <wire x2="2016" y1="864" y2="864" x1="1840" />
            <wire x2="2016" y1="864" y2="912" x1="2016" />
            <wire x2="2016" y1="912" y2="944" x1="2016" />
            <wire x2="2016" y1="944" y2="976" x1="2016" />
            <wire x2="2016" y1="976" y2="1008" x1="2016" />
            <wire x2="2016" y1="1008" y2="1072" x1="2016" />
            <wire x2="2016" y1="1072" y2="1136" x1="2016" />
            <wire x2="2016" y1="1136" y2="1168" x1="2016" />
            <wire x2="2016" y1="1168" y2="1216" x1="2016" />
        </branch>
        <branch name="Y(7)">
            <wire x2="2144" y1="944" y2="944" x1="2112" />
        </branch>
        <branch name="Y(1)">
            <wire x2="2144" y1="1008" y2="1008" x1="2112" />
        </branch>
        <branch name="Y(2)">
            <wire x2="2144" y1="1072" y2="1072" x1="2112" />
        </branch>
        <branch name="Y(4)">
            <wire x2="2144" y1="1136" y2="1136" x1="2112" />
        </branch>
        <branch name="F">
            <wire x2="2432" y1="1040" y2="1040" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1040" name="F" orien="R0" />
        <instance x="2144" y="1200" name="XLXI_3" orien="R0" />
        <instance x="1456" y="1216" name="XLXI_6" orien="R0">
        </instance>
        <bustap x2="2112" y1="1008" y2="1008" x1="2016" />
        <bustap x2="2112" y1="1072" y2="1072" x1="2016" />
        <bustap x2="2112" y1="1136" y2="1136" x1="2016" />
        <bustap x2="2112" y1="944" y2="944" x1="2016" />
    </sheet>
</drawing>