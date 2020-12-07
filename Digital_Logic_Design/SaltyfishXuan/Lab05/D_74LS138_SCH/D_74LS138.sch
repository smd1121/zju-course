<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="B" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="A" />
        <signal name="XLXN_15" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_38" />
        <signal name="XLXN_40" />
        <signal name="XLXN_41" />
        <signal name="XLXN_42" />
        <signal name="XLXN_44" />
        <signal name="XLXN_45" />
        <signal name="XLXN_46" />
        <signal name="XLXN_47" />
        <signal name="XLXN_48" />
        <signal name="XLXN_49" />
        <signal name="XLXN_50" />
        <signal name="XLXN_51" />
        <signal name="XLXN_52" />
        <signal name="XLXN_53" />
        <signal name="XLXN_55" />
        <signal name="XLXN_57" />
        <signal name="XLXN_59" />
        <signal name="XLXN_61" />
        <signal name="XLXN_63" />
        <signal name="G" />
        <signal name="G2A" />
        <signal name="G2B" />
        <signal name="XLXN_43" />
        <signal name="XLXN_69" />
        <signal name="C" />
        <signal name="XLXN_71" />
        <signal name="XLXN_72" />
        <signal name="XLXN_73" />
        <signal name="XLXN_76" />
        <signal name="XLXN_78" />
        <signal name="XLXN_79" />
        <signal name="XLXN_80" />
        <signal name="XLXN_81" />
        <signal name="XLXN_82" />
        <signal name="XLXN_83" />
        <signal name="XLXN_84" />
        <signal name="XLXN_85" />
        <signal name="XLXN_86" />
        <signal name="Y(7:0)" />
        <signal name="Y(7)" />
        <signal name="Y(6)" />
        <signal name="Y(4)" />
        <signal name="Y(3)" />
        <signal name="Y(5)" />
        <signal name="Y(0)" />
        <signal name="Y(1)" />
        <signal name="Y(2)" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="G" />
        <port polarity="Input" name="G2A" />
        <port polarity="Input" name="G2B" />
        <port polarity="Input" name="C" />
        <port polarity="Output" name="Y(7:0)" />
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
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="A" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_3">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_21" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_21" name="I0" />
            <blockpin signalname="XLXN_15" name="I1" />
            <blockpin signalname="XLXN_32" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="XLXN_21" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_34" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="XLXN_15" name="I1" />
            <blockpin signalname="XLXN_38" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_41" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_10">
            <blockpin signalname="XLXN_83" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_32" name="I2" />
            <blockpin signalname="Y(0)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_11">
            <blockpin signalname="XLXN_83" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_34" name="I2" />
            <blockpin signalname="Y(1)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_12">
            <blockpin signalname="XLXN_83" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_38" name="I2" />
            <blockpin signalname="Y(2)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_13">
            <blockpin signalname="XLXN_83" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_41" name="I2" />
            <blockpin signalname="Y(3)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_14">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_32" name="I2" />
            <blockpin signalname="Y(4)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_15">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_34" name="I2" />
            <blockpin signalname="Y(5)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_16">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_38" name="I2" />
            <blockpin signalname="Y(6)" name="O" />
        </block>
        <block symbolname="nand3" name="XLXI_17">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_53" name="I1" />
            <blockpin signalname="XLXN_41" name="I2" />
            <blockpin signalname="Y(7)" name="O" />
        </block>
        <block symbolname="nor3" name="XLXI_18">
            <blockpin signalname="G2B" name="I0" />
            <blockpin signalname="G2A" name="I1" />
            <blockpin signalname="XLXN_43" name="I2" />
            <blockpin signalname="XLXN_53" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="G" name="I" />
            <blockpin signalname="XLXN_43" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="XLXN_83" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="960" y="1376" name="XLXI_3" orien="R0" />
        <instance x="1440" y="768" name="XLXI_5" orien="R0" />
        <instance x="1424" y="1008" name="XLXI_6" orien="R0" />
        <instance x="1440" y="1280" name="XLXI_7" orien="R0" />
        <instance x="1440" y="1536" name="XLXI_8" orien="R0" />
        <branch name="B">
            <wire x2="848" y1="1472" y2="1472" x1="688" />
            <wire x2="1408" y1="1472" y2="1472" x1="848" />
            <wire x2="1440" y1="1472" y2="1472" x1="1408" />
            <wire x2="960" y1="1344" y2="1344" x1="848" />
            <wire x2="848" y1="1344" y2="1472" x1="848" />
            <wire x2="1440" y1="1216" y2="1216" x1="1408" />
            <wire x2="1408" y1="1216" y2="1472" x1="1408" />
        </branch>
        <instance x="960" y="704" name="XLXI_2" orien="R0" />
        <branch name="XLXN_15">
            <wire x2="1200" y1="672" y2="672" x1="1184" />
            <wire x2="1200" y1="672" y2="1152" x1="1200" />
            <wire x2="1440" y1="1152" y2="1152" x1="1200" />
            <wire x2="1200" y1="640" y2="672" x1="1200" />
            <wire x2="1440" y1="640" y2="640" x1="1200" />
        </branch>
        <branch name="XLXN_21">
            <wire x2="1280" y1="1344" y2="1344" x1="1184" />
            <wire x2="1440" y1="704" y2="704" x1="1280" />
            <wire x2="1280" y1="704" y2="944" x1="1280" />
            <wire x2="1280" y1="944" y2="1344" x1="1280" />
            <wire x2="1424" y1="944" y2="944" x1="1280" />
        </branch>
        <branch name="A">
            <wire x2="864" y1="880" y2="880" x1="688" />
            <wire x2="1344" y1="880" y2="880" x1="864" />
            <wire x2="1424" y1="880" y2="880" x1="1344" />
            <wire x2="1344" y1="880" y2="1408" x1="1344" />
            <wire x2="1440" y1="1408" y2="1408" x1="1344" />
            <wire x2="960" y1="672" y2="672" x1="864" />
            <wire x2="864" y1="672" y2="880" x1="864" />
        </branch>
        <instance x="2352" y="592" name="XLXI_10" orien="R0" />
        <instance x="2352" y="896" name="XLXI_11" orien="R0" />
        <instance x="2368" y="1200" name="XLXI_12" orien="R0" />
        <instance x="2368" y="1520" name="XLXI_13" orien="R0" />
        <instance x="2368" y="2080" name="XLXI_15" orien="R0" />
        <instance x="2352" y="2320" name="XLXI_16" orien="R0" />
        <branch name="XLXN_34">
            <wire x2="1840" y1="912" y2="912" x1="1680" />
            <wire x2="1840" y1="912" y2="1888" x1="1840" />
            <wire x2="2368" y1="1888" y2="1888" x1="1840" />
            <wire x2="2352" y1="704" y2="704" x1="1840" />
            <wire x2="1840" y1="704" y2="912" x1="1840" />
        </branch>
        <branch name="XLXN_38">
            <wire x2="1920" y1="1184" y2="1184" x1="1696" />
            <wire x2="1920" y1="1184" y2="2128" x1="1920" />
            <wire x2="2352" y1="2128" y2="2128" x1="1920" />
            <wire x2="2368" y1="1008" y2="1008" x1="1920" />
            <wire x2="1920" y1="1008" y2="1184" x1="1920" />
        </branch>
        <branch name="XLXN_41">
            <wire x2="1968" y1="1440" y2="1440" x1="1696" />
            <wire x2="1968" y1="1440" y2="2400" x1="1968" />
            <wire x2="2352" y1="2400" y2="2400" x1="1968" />
            <wire x2="2368" y1="1328" y2="1328" x1="1968" />
            <wire x2="1968" y1="1328" y2="1440" x1="1968" />
        </branch>
        <instance x="1424" y="2592" name="XLXI_18" orien="R0" />
        <branch name="G">
            <wire x2="992" y1="2400" y2="2400" x1="688" />
        </branch>
        <branch name="G2A">
            <wire x2="1424" y1="2464" y2="2464" x1="688" />
        </branch>
        <branch name="G2B">
            <wire x2="1424" y1="2528" y2="2528" x1="688" />
        </branch>
        <branch name="XLXN_43">
            <wire x2="1424" y1="2400" y2="2400" x1="1216" />
        </branch>
        <instance x="992" y="2432" name="XLXI_4" orien="R0" />
        <branch name="XLXN_53">
            <wire x2="2016" y1="2464" y2="2464" x1="1680" />
            <wire x2="2352" y1="2464" y2="2464" x1="2016" />
            <wire x2="2352" y1="464" y2="464" x1="2016" />
            <wire x2="2016" y1="464" y2="768" x1="2016" />
            <wire x2="2352" y1="768" y2="768" x1="2016" />
            <wire x2="2016" y1="768" y2="1072" x1="2016" />
            <wire x2="2368" y1="1072" y2="1072" x1="2016" />
            <wire x2="2016" y1="1072" y2="1392" x1="2016" />
            <wire x2="2368" y1="1392" y2="1392" x1="2016" />
            <wire x2="2016" y1="1392" y2="1664" x1="2016" />
            <wire x2="2016" y1="1664" y2="1952" x1="2016" />
            <wire x2="2368" y1="1952" y2="1952" x1="2016" />
            <wire x2="2016" y1="1952" y2="2192" x1="2016" />
            <wire x2="2352" y1="2192" y2="2192" x1="2016" />
            <wire x2="2016" y1="2192" y2="2464" x1="2016" />
            <wire x2="2368" y1="1664" y2="1664" x1="2016" />
        </branch>
        <instance x="2352" y="2592" name="XLXI_17" orien="R0" />
        <branch name="C">
            <wire x2="1040" y1="2016" y2="2016" x1="688" />
            <wire x2="2272" y1="2016" y2="2016" x1="1040" />
            <wire x2="2368" y1="2016" y2="2016" x1="2272" />
            <wire x2="2272" y1="2016" y2="2256" x1="2272" />
            <wire x2="2352" y1="2256" y2="2256" x1="2272" />
            <wire x2="2272" y1="2256" y2="2528" x1="2272" />
            <wire x2="2352" y1="2528" y2="2528" x1="2272" />
            <wire x2="1376" y1="1808" y2="1808" x1="1040" />
            <wire x2="1040" y1="1808" y2="2016" x1="1040" />
            <wire x2="2272" y1="1728" y2="2016" x1="2272" />
            <wire x2="2368" y1="1728" y2="1728" x1="2272" />
        </branch>
        <branch name="XLXN_32">
            <wire x2="1776" y1="672" y2="672" x1="1696" />
            <wire x2="1776" y1="672" y2="1600" x1="1776" />
            <wire x2="2368" y1="1600" y2="1600" x1="1776" />
            <wire x2="2352" y1="400" y2="400" x1="1776" />
            <wire x2="1776" y1="400" y2="672" x1="1776" />
        </branch>
        <instance x="2368" y="1792" name="XLXI_14" orien="R0" />
        <instance x="1376" y="1840" name="XLXI_9" orien="R0" />
        <branch name="XLXN_83">
            <wire x2="2144" y1="1808" y2="1808" x1="1600" />
            <wire x2="2144" y1="528" y2="832" x1="2144" />
            <wire x2="2144" y1="832" y2="1136" x1="2144" />
            <wire x2="2144" y1="1136" y2="1456" x1="2144" />
            <wire x2="2144" y1="1456" y2="1808" x1="2144" />
            <wire x2="2368" y1="1456" y2="1456" x1="2144" />
            <wire x2="2368" y1="1136" y2="1136" x1="2144" />
            <wire x2="2352" y1="832" y2="832" x1="2144" />
            <wire x2="2352" y1="528" y2="528" x1="2144" />
        </branch>
        <branch name="Y(7:0)">
            <wire x2="2816" y1="336" y2="464" x1="2816" />
            <wire x2="2816" y1="464" y2="768" x1="2816" />
            <wire x2="2816" y1="768" y2="1072" x1="2816" />
            <wire x2="2816" y1="1072" y2="1392" x1="2816" />
            <wire x2="2816" y1="1392" y2="1552" x1="2816" />
            <wire x2="2912" y1="1552" y2="1552" x1="2816" />
            <wire x2="2816" y1="1552" y2="1664" x1="2816" />
            <wire x2="2816" y1="1664" y2="1952" x1="2816" />
            <wire x2="2816" y1="1952" y2="2192" x1="2816" />
            <wire x2="2816" y1="2192" y2="2464" x1="2816" />
            <wire x2="2816" y1="2464" y2="2512" x1="2816" />
        </branch>
        <iomarker fontsize="28" x="2912" y="1552" name="Y(7:0)" orien="R0" />
        <branch name="Y(7)">
            <wire x2="2720" y1="2464" y2="2464" x1="2608" />
        </branch>
        <branch name="Y(6)">
            <wire x2="2720" y1="2192" y2="2192" x1="2608" />
        </branch>
        <branch name="Y(4)">
            <wire x2="2720" y1="1664" y2="1664" x1="2624" />
        </branch>
        <branch name="Y(3)">
            <wire x2="2640" y1="1392" y2="1392" x1="2624" />
            <wire x2="2720" y1="1392" y2="1392" x1="2640" />
        </branch>
        <branch name="Y(5)">
            <wire x2="2720" y1="1952" y2="1952" x1="2624" />
        </branch>
        <branch name="Y(0)">
            <wire x2="2720" y1="464" y2="464" x1="2608" />
        </branch>
        <branch name="Y(1)">
            <wire x2="2720" y1="768" y2="768" x1="2608" />
        </branch>
        <branch name="Y(2)">
            <wire x2="2720" y1="1072" y2="1072" x1="2624" />
        </branch>
        <iomarker fontsize="28" x="688" y="2016" name="C" orien="R180" />
        <iomarker fontsize="28" x="688" y="2400" name="G" orien="R180" />
        <iomarker fontsize="28" x="688" y="2464" name="G2A" orien="R180" />
        <iomarker fontsize="28" x="688" y="2528" name="G2B" orien="R180" />
        <iomarker fontsize="28" x="688" y="1472" name="B" orien="R180" />
        <iomarker fontsize="28" x="688" y="880" name="A" orien="R180" />
        <bustap x2="2720" y1="464" y2="464" x1="2816" />
        <bustap x2="2720" y1="768" y2="768" x1="2816" />
        <bustap x2="2720" y1="1072" y2="1072" x1="2816" />
        <bustap x2="2720" y1="1392" y2="1392" x1="2816" />
        <bustap x2="2720" y1="1664" y2="1664" x1="2816" />
        <bustap x2="2720" y1="1952" y2="1952" x1="2816" />
        <bustap x2="2720" y1="2192" y2="2192" x1="2816" />
        <bustap x2="2720" y1="2464" y2="2464" x1="2816" />
    </sheet>
</drawing>