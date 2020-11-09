<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="s(1:0)" />
        <signal name="s(1)" />
        <signal name="s(0)" />
        <signal name="ns1" />
        <signal name="ns0" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="o" />
        <signal name="I0" />
        <signal name="I1" />
        <signal name="I2" />
        <signal name="I3" />
        <port polarity="Input" name="s(1:0)" />
        <port polarity="Output" name="o" />
        <port polarity="Input" name="I0" />
        <port polarity="Input" name="I1" />
        <port polarity="Input" name="I2" />
        <port polarity="Input" name="I3" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="ns0" name="I0" />
            <blockpin signalname="ns1" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="s(0)" name="I0" />
            <blockpin signalname="ns1" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="ns0" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="s(0)" name="I1" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="s(1)" name="I" />
            <blockpin signalname="ns1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin signalname="s(0)" name="I" />
            <blockpin signalname="ns0" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="I0" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="I1" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="I2" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="I3" name="I0" />
            <blockpin signalname="XLXN_9" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_11">
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_11" name="I2" />
            <blockpin signalname="XLXN_10" name="I3" />
            <blockpin signalname="o" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="s(1:0)">
            <wire x2="848" y1="512" y2="512" x1="624" />
            <wire x2="848" y1="512" y2="544" x1="848" />
            <wire x2="848" y1="544" y2="624" x1="848" />
            <wire x2="848" y1="624" y2="672" x1="848" />
        </branch>
        <bustap x2="944" y1="544" y2="544" x1="848" />
        <branch name="s(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="960" y="544" type="branch" />
            <wire x2="1008" y1="448" y2="448" x1="784" />
            <wire x2="1008" y1="448" y2="544" x1="1008" />
            <wire x2="1024" y1="544" y2="544" x1="1008" />
            <wire x2="784" y1="448" y2="912" x1="784" />
            <wire x2="784" y1="912" y2="1056" x1="784" />
            <wire x2="1296" y1="1056" y2="1056" x1="784" />
            <wire x2="1296" y1="912" y2="912" x1="784" />
            <wire x2="960" y1="544" y2="544" x1="944" />
            <wire x2="1008" y1="544" y2="544" x1="960" />
        </branch>
        <bustap x2="944" y1="624" y2="624" x1="848" />
        <branch name="s(0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="968" y="624" type="branch" />
            <wire x2="960" y1="624" y2="624" x1="944" />
            <wire x2="960" y1="624" y2="768" x1="960" />
            <wire x2="1296" y1="768" y2="768" x1="960" />
            <wire x2="960" y1="768" y2="992" x1="960" />
            <wire x2="1296" y1="992" y2="992" x1="960" />
            <wire x2="976" y1="624" y2="624" x1="960" />
            <wire x2="992" y1="624" y2="624" x1="976" />
        </branch>
        <instance x="1296" y="672" name="XLXI_1" orien="R0" />
        <instance x="1296" y="832" name="XLXI_2" orien="R0" />
        <instance x="1296" y="976" name="XLXI_3" orien="R0" />
        <instance x="1296" y="1120" name="XLXI_4" orien="R0" />
        <instance x="1024" y="576" name="XLXI_5" orien="R0" />
        <branch name="ns1">
            <wire x2="1264" y1="544" y2="544" x1="1248" />
            <wire x2="1296" y1="544" y2="544" x1="1264" />
            <wire x2="1264" y1="544" y2="704" x1="1264" />
            <wire x2="1296" y1="704" y2="704" x1="1264" />
        </branch>
        <instance x="992" y="656" name="XLXI_6" orien="R0" />
        <branch name="ns0">
            <wire x2="1232" y1="624" y2="624" x1="1216" />
            <wire x2="1280" y1="624" y2="624" x1="1232" />
            <wire x2="1232" y1="624" y2="848" x1="1232" />
            <wire x2="1296" y1="848" y2="848" x1="1232" />
            <wire x2="1296" y1="608" y2="608" x1="1280" />
            <wire x2="1280" y1="608" y2="624" x1="1280" />
        </branch>
        <iomarker fontsize="28" x="624" y="512" name="s(1:0)" orien="R180" />
        <instance x="1888" y="704" name="XLXI_7" orien="R0" />
        <instance x="1888" y="848" name="XLXI_8" orien="R0" />
        <instance x="1888" y="1008" name="XLXI_9" orien="R0" />
        <instance x="1888" y="1152" name="XLXI_10" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1888" y1="576" y2="576" x1="1552" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1712" y1="736" y2="736" x1="1552" />
            <wire x2="1712" y1="720" y2="736" x1="1712" />
            <wire x2="1888" y1="720" y2="720" x1="1712" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1888" y1="880" y2="880" x1="1552" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1888" y1="1024" y2="1024" x1="1552" />
        </branch>
        <instance x="2288" y="976" name="XLXI_11" orien="R0" />
        <branch name="XLXN_10">
            <wire x2="2288" y1="608" y2="608" x1="2144" />
            <wire x2="2288" y1="608" y2="720" x1="2288" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="2208" y1="752" y2="752" x1="2144" />
            <wire x2="2208" y1="752" y2="784" x1="2208" />
            <wire x2="2288" y1="784" y2="784" x1="2208" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="2208" y1="912" y2="912" x1="2144" />
            <wire x2="2208" y1="848" y2="912" x1="2208" />
            <wire x2="2288" y1="848" y2="848" x1="2208" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="2160" y1="1056" y2="1056" x1="2144" />
            <wire x2="2288" y1="1056" y2="1056" x1="2160" />
            <wire x2="2288" y1="912" y2="1056" x1="2288" />
        </branch>
        <branch name="o">
            <wire x2="2672" y1="816" y2="816" x1="2544" />
        </branch>
        <iomarker fontsize="28" x="2672" y="816" name="o" orien="R0" />
        <branch name="I0">
            <wire x2="1552" y1="1232" y2="1232" x1="368" />
            <wire x2="1568" y1="1232" y2="1232" x1="1552" />
            <wire x2="1888" y1="640" y2="640" x1="1568" />
            <wire x2="1568" y1="640" y2="1232" x1="1568" />
        </branch>
        <branch name="I1">
            <wire x2="384" y1="1296" y2="1296" x1="368" />
            <wire x2="1568" y1="1296" y2="1296" x1="384" />
            <wire x2="1584" y1="1296" y2="1296" x1="1568" />
            <wire x2="1888" y1="784" y2="784" x1="1584" />
            <wire x2="1584" y1="784" y2="1296" x1="1584" />
        </branch>
        <branch name="I2">
            <wire x2="1584" y1="1360" y2="1360" x1="368" />
            <wire x2="1616" y1="1360" y2="1360" x1="1584" />
            <wire x2="1888" y1="944" y2="944" x1="1616" />
            <wire x2="1616" y1="944" y2="1360" x1="1616" />
        </branch>
        <iomarker fontsize="28" x="368" y="1232" name="I0" orien="R180" />
        <iomarker fontsize="28" x="368" y="1296" name="I1" orien="R180" />
        <iomarker fontsize="28" x="368" y="1360" name="I2" orien="R180" />
        <branch name="I3">
            <wire x2="1872" y1="1440" y2="1440" x1="368" />
            <wire x2="1888" y1="1088" y2="1088" x1="1872" />
            <wire x2="1872" y1="1088" y2="1440" x1="1872" />
        </branch>
        <iomarker fontsize="28" x="368" y="1440" name="I3" orien="R180" />
    </sheet>
</drawing>