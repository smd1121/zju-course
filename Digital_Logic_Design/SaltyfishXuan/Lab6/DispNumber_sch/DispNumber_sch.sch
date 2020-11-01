<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="SW(7:0)" />
        <signal name="point" />
        <signal name="LE" />
        <signal name="XLXN_5" />
        <signal name="SW(0)" />
        <signal name="SW(1)" />
        <signal name="SW(2)" />
        <signal name="SW(3)" />
        <signal name="SW(7)" />
        <signal name="SW(6)" />
        <signal name="SW(5)" />
        <signal name="SW(4)" />
        <signal name="SEGMENT(7:0)" />
        <signal name="AN(3:0)" />
        <signal name="SEGMENT(7)" />
        <signal name="SEGMENT(6)" />
        <signal name="SEGMENT(5)" />
        <signal name="SEGMENT(4)" />
        <signal name="SEGMENT(3)" />
        <signal name="SEGMENT(2)" />
        <signal name="SEGMENT(1)" />
        <signal name="SEGMENT(0)" />
        <signal name="AN(3)" />
        <signal name="AN(2)" />
        <signal name="AN(1)" />
        <signal name="AN(0)" />
        <port polarity="Input" name="SW(7:0)" />
        <port polarity="Input" name="point" />
        <port polarity="Input" name="LE" />
        <port polarity="Output" name="SEGMENT(7:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <blockdef name="MyMC14495">
            <timestamp>2020-10-29T8:32:36</timestamp>
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="MyMC14495" name="XLXI_1">
            <blockpin signalname="point" name="point" />
            <blockpin signalname="LE" name="LE" />
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
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="SW(4)" name="I" />
            <blockpin signalname="AN(0)" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_3">
            <blockpin signalname="SW(5)" name="I" />
            <blockpin signalname="AN(1)" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="SW(6)" name="I" />
            <blockpin signalname="AN(2)" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="SW(7)" name="I" />
            <blockpin signalname="AN(3)" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="7040" height="5440">
        <instance x="2672" y="2192" name="XLXI_1" orien="R0">
        </instance>
        <branch name="point">
            <wire x2="2672" y1="1712" y2="1712" x1="2640" />
        </branch>
        <iomarker fontsize="28" x="2640" y="1712" name="point" orien="R180" />
        <branch name="LE">
            <wire x2="2672" y1="1792" y2="1792" x1="2640" />
        </branch>
        <iomarker fontsize="28" x="2640" y="1792" name="LE" orien="R180" />
        <branch name="SW(7:0)">
            <attrtext style="alignment:SOFT-VRIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2464" y="2672" type="branch" />
            <wire x2="2464" y1="1664" y2="1872" x1="2464" />
            <wire x2="2464" y1="1872" y2="1952" x1="2464" />
            <wire x2="2464" y1="1952" y2="2032" x1="2464" />
            <wire x2="2464" y1="2032" y2="2112" x1="2464" />
            <wire x2="2464" y1="2112" y2="2304" x1="2464" />
            <wire x2="2464" y1="2304" y2="2384" x1="2464" />
            <wire x2="2464" y1="2384" y2="2448" x1="2464" />
            <wire x2="2464" y1="2448" y2="2464" x1="2464" />
            <wire x2="2464" y1="2464" y2="2544" x1="2464" />
            <wire x2="2464" y1="2544" y2="2672" x1="2464" />
        </branch>
        <iomarker fontsize="28" x="2464" y="1664" name="SW(7:0)" orien="R270" />
        <bustap x2="2560" y1="2112" y2="2112" x1="2464" />
        <branch name="SW(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2616" y="2112" type="branch" />
            <wire x2="2616" y1="2112" y2="2112" x1="2560" />
            <wire x2="2672" y1="2112" y2="2112" x1="2616" />
        </branch>
        <bustap x2="2560" y1="2032" y2="2032" x1="2464" />
        <branch name="SW(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2616" y="2032" type="branch" />
            <wire x2="2616" y1="2032" y2="2032" x1="2560" />
            <wire x2="2672" y1="2032" y2="2032" x1="2616" />
        </branch>
        <bustap x2="2560" y1="1952" y2="1952" x1="2464" />
        <branch name="SW(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2616" y="1952" type="branch" />
            <wire x2="2616" y1="1952" y2="1952" x1="2560" />
            <wire x2="2672" y1="1952" y2="1952" x1="2616" />
        </branch>
        <bustap x2="2560" y1="1872" y2="1872" x1="2464" />
        <branch name="SW(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2616" y="1872" type="branch" />
            <wire x2="2616" y1="1872" y2="1872" x1="2560" />
            <wire x2="2672" y1="1872" y2="1872" x1="2616" />
        </branch>
        <instance x="2752" y="2336" name="XLXI_2" orien="R0" />
        <instance x="2752" y="2416" name="XLXI_3" orien="R0" />
        <instance x="2752" y="2496" name="XLXI_4" orien="R0" />
        <instance x="2752" y="2576" name="XLXI_5" orien="R0" />
        <bustap x2="2560" y1="2544" y2="2544" x1="2464" />
        <branch name="SW(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2656" y="2544" type="branch" />
            <wire x2="2656" y1="2544" y2="2544" x1="2560" />
            <wire x2="2752" y1="2544" y2="2544" x1="2656" />
        </branch>
        <bustap x2="2560" y1="2464" y2="2464" x1="2464" />
        <branch name="SW(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2656" y="2464" type="branch" />
            <wire x2="2656" y1="2464" y2="2464" x1="2560" />
            <wire x2="2752" y1="2464" y2="2464" x1="2656" />
        </branch>
        <bustap x2="2560" y1="2384" y2="2384" x1="2464" />
        <branch name="SW(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2656" y="2384" type="branch" />
            <wire x2="2656" y1="2384" y2="2384" x1="2560" />
            <wire x2="2752" y1="2384" y2="2384" x1="2656" />
        </branch>
        <bustap x2="2560" y1="2304" y2="2304" x1="2464" />
        <branch name="SW(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2656" y="2304" type="branch" />
            <wire x2="2656" y1="2304" y2="2304" x1="2560" />
            <wire x2="2752" y1="2304" y2="2304" x1="2656" />
        </branch>
        <branch name="SEGMENT(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3280" y="1865" type="branch" />
            <wire x2="3280" y1="1632" y2="1712" x1="3280" />
            <wire x2="3280" y1="1712" y2="1776" x1="3280" />
            <wire x2="3280" y1="1776" y2="1840" x1="3280" />
            <wire x2="3280" y1="1840" y2="1865" x1="3280" />
            <wire x2="3280" y1="1865" y2="1904" x1="3280" />
            <wire x2="3280" y1="1904" y2="1968" x1="3280" />
            <wire x2="3280" y1="1968" y2="2032" x1="3280" />
            <wire x2="3280" y1="2032" y2="2096" x1="3280" />
            <wire x2="3280" y1="2096" y2="2160" x1="3280" />
            <wire x2="3280" y1="2160" y2="2208" x1="3280" />
        </branch>
        <branch name="AN(3:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3136" y="2447" type="branch" />
            <wire x2="3136" y1="2256" y2="2304" x1="3136" />
            <wire x2="3136" y1="2304" y2="2384" x1="3136" />
            <wire x2="3136" y1="2384" y2="2447" x1="3136" />
            <wire x2="3136" y1="2447" y2="2464" x1="3136" />
            <wire x2="3136" y1="2464" y2="2544" x1="3136" />
            <wire x2="3136" y1="2544" y2="2640" x1="3136" />
        </branch>
        <iomarker fontsize="28" x="3280" y="1632" name="SEGMENT(7:0)" orien="R270" />
        <bustap x2="3184" y1="1712" y2="1712" x1="3280" />
        <branch name="SEGMENT(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="1712" type="branch" />
            <wire x2="3120" y1="1712" y2="1712" x1="3056" />
            <wire x2="3184" y1="1712" y2="1712" x1="3120" />
        </branch>
        <bustap x2="3184" y1="2160" y2="2160" x1="3280" />
        <branch name="SEGMENT(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="2160" type="branch" />
            <wire x2="3120" y1="2160" y2="2160" x1="3056" />
            <wire x2="3184" y1="2160" y2="2160" x1="3120" />
        </branch>
        <bustap x2="3184" y1="2096" y2="2096" x1="3280" />
        <branch name="SEGMENT(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="2096" type="branch" />
            <wire x2="3120" y1="2096" y2="2096" x1="3056" />
            <wire x2="3184" y1="2096" y2="2096" x1="3120" />
        </branch>
        <bustap x2="3184" y1="2032" y2="2032" x1="3280" />
        <branch name="SEGMENT(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="2032" type="branch" />
            <wire x2="3120" y1="2032" y2="2032" x1="3056" />
            <wire x2="3184" y1="2032" y2="2032" x1="3120" />
        </branch>
        <bustap x2="3184" y1="1968" y2="1968" x1="3280" />
        <branch name="SEGMENT(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="1968" type="branch" />
            <wire x2="3120" y1="1968" y2="1968" x1="3056" />
            <wire x2="3184" y1="1968" y2="1968" x1="3120" />
        </branch>
        <bustap x2="3184" y1="1904" y2="1904" x1="3280" />
        <branch name="SEGMENT(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="1904" type="branch" />
            <wire x2="3120" y1="1904" y2="1904" x1="3056" />
            <wire x2="3184" y1="1904" y2="1904" x1="3120" />
        </branch>
        <bustap x2="3184" y1="1840" y2="1840" x1="3280" />
        <branch name="SEGMENT(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="1840" type="branch" />
            <wire x2="3120" y1="1840" y2="1840" x1="3056" />
            <wire x2="3184" y1="1840" y2="1840" x1="3120" />
        </branch>
        <bustap x2="3184" y1="1776" y2="1776" x1="3280" />
        <branch name="SEGMENT(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3120" y="1776" type="branch" />
            <wire x2="3120" y1="1776" y2="1776" x1="3056" />
            <wire x2="3184" y1="1776" y2="1776" x1="3120" />
        </branch>
        <iomarker fontsize="28" x="3136" y="2640" name="AN(3:0)" orien="R90" />
        <bustap x2="3040" y1="2544" y2="2544" x1="3136" />
        <branch name="AN(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3008" y="2544" type="branch" />
            <wire x2="3008" y1="2544" y2="2544" x1="2976" />
            <wire x2="3040" y1="2544" y2="2544" x1="3008" />
        </branch>
        <bustap x2="3040" y1="2464" y2="2464" x1="3136" />
        <branch name="AN(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3008" y="2464" type="branch" />
            <wire x2="3008" y1="2464" y2="2464" x1="2976" />
            <wire x2="3040" y1="2464" y2="2464" x1="3008" />
        </branch>
        <bustap x2="3040" y1="2384" y2="2384" x1="3136" />
        <branch name="AN(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3008" y="2384" type="branch" />
            <wire x2="3008" y1="2384" y2="2384" x1="2976" />
            <wire x2="3040" y1="2384" y2="2384" x1="3008" />
        </branch>
        <bustap x2="3040" y1="2304" y2="2304" x1="3136" />
        <branch name="AN(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3008" y="2304" type="branch" />
            <wire x2="3008" y1="2304" y2="2304" x1="2976" />
            <wire x2="3040" y1="2304" y2="2304" x1="3008" />
        </branch>
    </sheet>
</drawing>