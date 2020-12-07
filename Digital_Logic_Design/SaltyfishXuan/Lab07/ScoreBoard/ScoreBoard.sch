<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="clk_100mhz" />
        <signal name="RSTN" />
        <signal name="clkdiv(31:0)" />
        <signal name="clkdiv(17)" />
        <signal name="clkdiv(18:17)" />
        <signal name="num(15:0)" />
        <signal name="XLXN_7" />
        <signal name="num(3:0)" />
        <signal name="num(11:8)" />
        <signal name="num(15:12)" />
        <signal name="num(7:4)" />
        <signal name="btn(3:0)" />
        <signal name="XLXN_14(1:0)" />
        <signal name="XLXN_15(1:0)" />
        <signal name="XLXN_18(1:0)" />
        <signal name="XLXN_19(1:0)" />
        <signal name="SW(7:0)" />
        <signal name="SW(7)" />
        <signal name="SW(6)" />
        <signal name="SW(5)" />
        <signal name="SW(4)" />
        <signal name="SW(3)" />
        <signal name="SW(2)" />
        <signal name="SW(1)" />
        <signal name="SW(0)" />
        <signal name="V5" />
        <signal name="V0" />
        <signal name="V5,V5,V5,V0" />
        <signal name="V5,V0,V5,V5" />
        <signal name="V0,V5,V5,V5" />
        <signal name="V5,V5,V0,V5" />
        <signal name="AN(3:0)" />
        <signal name="o(3:0)" />
        <signal name="o(3)" />
        <signal name="o(2)" />
        <signal name="o(1)" />
        <signal name="o(0)" />
        <signal name="XLXN_45" />
        <signal name="XLXN_46" />
        <signal name="XLXN_47" />
        <signal name="XLXN_48" />
        <signal name="XLXN_49" />
        <signal name="XLXN_50" />
        <signal name="SEGMENT(7:0)" />
        <signal name="SEGMENT(7)" />
        <signal name="SEGMENT(6)" />
        <signal name="SEGMENT(5)" />
        <signal name="SEGMENT(4)" />
        <signal name="SEGMENT(3)" />
        <signal name="SEGMENT(2)" />
        <signal name="SEGMENT(1)" />
        <signal name="SEGMENT(0)" />
        <signal name="BN" />
        <signal name="K_ROW" />
        <port polarity="Input" name="clk_100mhz" />
        <port polarity="Input" name="RSTN" />
        <port polarity="Input" name="btn(3:0)" />
        <port polarity="Input" name="SW(7:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="SEGMENT(7:0)" />
        <port polarity="Input" name="BN" />
        <port polarity="Output" name="K_ROW" />
        <blockdef name="clkdiv">
            <timestamp>2020-11-9T7:33:44</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="CreateNumber">
            <timestamp>2020-11-9T7:47:26</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="Mux4to1b4">
            <timestamp>2020-11-9T7:2:48</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
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
        <blockdef name="Mux4to1">
            <timestamp>2020-11-9T7:24:16</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
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
        <blockdef name="buf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="0" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="64" y1="-64" y2="0" x1="64" />
        </blockdef>
        <block symbolname="clkdiv" name="XLXI_1">
            <blockpin signalname="clk_100mhz" name="clk" />
            <blockpin signalname="RSTN" name="rst" />
            <blockpin signalname="clkdiv(31:0)" name="clkdiv(31:0)" />
        </block>
        <block symbolname="CreateNumber" name="XLXI_2">
            <blockpin signalname="clkdiv(17)" name="clk" />
            <blockpin signalname="btn(3:0)" name="btn(3:0)" />
            <blockpin signalname="num(15:0)" name="num(15:0)" />
        </block>
        <block symbolname="Mux4to1b4" name="XLXI_3">
            <blockpin signalname="clkdiv(18:17)" name="s(1:0)" />
            <blockpin signalname="num(3:0)" name="I0(3:0)" />
            <blockpin signalname="num(11:8)" name="I2(3:0)" />
            <blockpin signalname="num(15:12)" name="I3(3:0)" />
            <blockpin signalname="num(7:4)" name="I1(3:0)" />
            <blockpin signalname="o(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="MyMC14495" name="XLXI_4">
            <blockpin signalname="XLXN_45" name="point" />
            <blockpin signalname="XLXN_46" name="LE" />
            <blockpin signalname="o(3)" name="D3" />
            <blockpin signalname="o(2)" name="D2" />
            <blockpin signalname="o(1)" name="D1" />
            <blockpin signalname="o(0)" name="D0" />
            <blockpin signalname="SEGMENT(7)" name="p" />
            <blockpin signalname="SEGMENT(0)" name="a" />
            <blockpin signalname="SEGMENT(1)" name="b" />
            <blockpin signalname="SEGMENT(2)" name="c" />
            <blockpin signalname="SEGMENT(3)" name="d" />
            <blockpin signalname="SEGMENT(4)" name="e" />
            <blockpin signalname="SEGMENT(5)" name="f" />
            <blockpin signalname="SEGMENT(6)" name="g" />
        </block>
        <block symbolname="Mux4to1" name="XLXI_5">
            <blockpin signalname="clkdiv(18:17)" name="s(1:0)" />
            <blockpin signalname="SW(0)" name="I0" />
            <blockpin signalname="SW(1)" name="I1" />
            <blockpin signalname="SW(2)" name="I2" />
            <blockpin signalname="SW(3)" name="I3" />
            <blockpin signalname="XLXN_46" name="o" />
        </block>
        <block symbolname="Mux4to1" name="XLXI_6">
            <blockpin signalname="clkdiv(18:17)" name="s(1:0)" />
            <blockpin signalname="SW(4)" name="I0" />
            <blockpin signalname="SW(5)" name="I1" />
            <blockpin signalname="SW(6)" name="I2" />
            <blockpin signalname="SW(7)" name="I3" />
            <blockpin signalname="XLXN_45" name="o" />
        </block>
        <block symbolname="Mux4to1b4" name="XLXI_7">
            <blockpin signalname="clkdiv(18:17)" name="s(1:0)" />
            <blockpin signalname="V5,V5,V5,V0" name="I0(3:0)" />
            <blockpin signalname="V5,V0,V5,V5" name="I2(3:0)" />
            <blockpin signalname="V0,V5,V5,V5" name="I3(3:0)" />
            <blockpin signalname="V5,V5,V0,V5" name="I1(3:0)" />
            <blockpin signalname="AN(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="vcc" name="XLXI_8">
            <blockpin signalname="V5" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_9">
            <blockpin signalname="V0" name="G" />
        </block>
        <block symbolname="buf" name="XLXI_10">
            <blockpin signalname="BN" name="I" />
            <blockpin signalname="K_ROW" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="7040" height="5440">
        <instance x="1536" y="240" name="XLXI_1" orien="R0">
        </instance>
        <branch name="clk_100mhz">
            <wire x2="1536" y1="144" y2="144" x1="1504" />
        </branch>
        <iomarker fontsize="28" x="1504" y="144" name="clk_100mhz" orien="R180" />
        <branch name="RSTN">
            <wire x2="1536" y1="208" y2="208" x1="1504" />
        </branch>
        <iomarker fontsize="28" x="1504" y="208" name="RSTN" orien="R180" />
        <branch name="clkdiv(31:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1984" y="258" type="branch" />
            <wire x2="1984" y1="144" y2="144" x1="1920" />
            <wire x2="1984" y1="144" y2="258" x1="1984" />
            <wire x2="1984" y1="258" y2="288" x1="1984" />
            <wire x2="1984" y1="288" y2="368" x1="1984" />
            <wire x2="1984" y1="368" y2="416" x1="1984" />
        </branch>
        <branch name="clkdiv(17)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1872" y="288" type="branch" />
            <wire x2="528" y1="288" y2="512" x1="528" />
            <wire x2="576" y1="512" y2="512" x1="528" />
            <wire x2="1872" y1="288" y2="288" x1="528" />
            <wire x2="1888" y1="288" y2="288" x1="1872" />
        </branch>
        <bustap x2="1888" y1="288" y2="288" x1="1984" />
        <bustap x2="1888" y1="368" y2="368" x1="1984" />
        <instance x="1552" y="1728" name="XLXI_6" orien="R0">
        </instance>
        <instance x="1552" y="2160" name="XLXI_7" orien="R0">
        </instance>
        <instance x="576" y="608" name="XLXI_2" orien="R0">
        </instance>
        <branch name="num(15:0)">
            <wire x2="1056" y1="512" y2="512" x1="960" />
            <wire x2="1056" y1="512" y2="608" x1="1056" />
            <wire x2="1056" y1="608" y2="672" x1="1056" />
            <wire x2="1056" y1="672" y2="736" x1="1056" />
            <wire x2="1056" y1="736" y2="800" x1="1056" />
            <wire x2="1056" y1="800" y2="848" x1="1056" />
        </branch>
        <bustap x2="1152" y1="608" y2="608" x1="1056" />
        <branch name="num(3:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1352" y="608" type="branch" />
            <wire x2="1352" y1="608" y2="608" x1="1152" />
            <wire x2="1552" y1="608" y2="608" x1="1352" />
        </branch>
        <bustap x2="1152" y1="672" y2="672" x1="1056" />
        <branch name="num(11:8)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1352" y="672" type="branch" />
            <wire x2="1352" y1="672" y2="672" x1="1152" />
            <wire x2="1552" y1="672" y2="672" x1="1352" />
        </branch>
        <bustap x2="1152" y1="736" y2="736" x1="1056" />
        <branch name="num(15:12)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1352" y="736" type="branch" />
            <wire x2="1352" y1="736" y2="736" x1="1152" />
            <wire x2="1552" y1="736" y2="736" x1="1352" />
        </branch>
        <bustap x2="1152" y1="800" y2="800" x1="1056" />
        <branch name="num(7:4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1352" y="800" type="branch" />
            <wire x2="1352" y1="800" y2="800" x1="1152" />
            <wire x2="1552" y1="800" y2="800" x1="1352" />
        </branch>
        <branch name="btn(3:0)">
            <wire x2="576" y1="576" y2="576" x1="544" />
        </branch>
        <iomarker fontsize="28" x="544" y="576" name="btn(3:0)" orien="R180" />
        <branch name="clkdiv(18:17)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1712" y="368" type="branch" />
            <wire x2="1488" y1="368" y2="544" x1="1488" />
            <wire x2="1552" y1="544" y2="544" x1="1488" />
            <wire x2="1488" y1="544" y2="1008" x1="1488" />
            <wire x2="1488" y1="1008" y2="1440" x1="1488" />
            <wire x2="1552" y1="1440" y2="1440" x1="1488" />
            <wire x2="1488" y1="1440" y2="1872" x1="1488" />
            <wire x2="1552" y1="1872" y2="1872" x1="1488" />
            <wire x2="1552" y1="1008" y2="1008" x1="1488" />
            <wire x2="1712" y1="368" y2="368" x1="1488" />
            <wire x2="1888" y1="368" y2="368" x1="1712" />
        </branch>
        <branch name="SW(7:0)">
            <wire x2="864" y1="960" y2="1056" x1="864" />
            <wire x2="864" y1="1056" y2="1072" x1="864" />
            <wire x2="864" y1="1072" y2="1136" x1="864" />
            <wire x2="864" y1="1136" y2="1200" x1="864" />
            <wire x2="864" y1="1200" y2="1264" x1="864" />
            <wire x2="864" y1="1264" y2="1504" x1="864" />
            <wire x2="864" y1="1504" y2="1568" x1="864" />
            <wire x2="864" y1="1568" y2="1632" x1="864" />
            <wire x2="864" y1="1632" y2="1696" x1="864" />
            <wire x2="864" y1="1696" y2="1744" x1="864" />
        </branch>
        <bustap x2="960" y1="1696" y2="1696" x1="864" />
        <branch name="SW(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1696" type="branch" />
            <wire x2="1256" y1="1696" y2="1696" x1="960" />
            <wire x2="1552" y1="1696" y2="1696" x1="1256" />
        </branch>
        <bustap x2="960" y1="1632" y2="1632" x1="864" />
        <branch name="SW(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1632" type="branch" />
            <wire x2="1256" y1="1632" y2="1632" x1="960" />
            <wire x2="1552" y1="1632" y2="1632" x1="1256" />
        </branch>
        <bustap x2="960" y1="1568" y2="1568" x1="864" />
        <branch name="SW(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1568" type="branch" />
            <wire x2="1256" y1="1568" y2="1568" x1="960" />
            <wire x2="1552" y1="1568" y2="1568" x1="1256" />
        </branch>
        <bustap x2="960" y1="1504" y2="1504" x1="864" />
        <branch name="SW(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1504" type="branch" />
            <wire x2="1256" y1="1504" y2="1504" x1="960" />
            <wire x2="1552" y1="1504" y2="1504" x1="1256" />
        </branch>
        <bustap x2="960" y1="1264" y2="1264" x1="864" />
        <bustap x2="960" y1="1200" y2="1200" x1="864" />
        <bustap x2="960" y1="1136" y2="1136" x1="864" />
        <bustap x2="960" y1="1072" y2="1072" x1="864" />
        <branch name="V5">
            <attrtext style="alignment:SOFT-VRIGHT;fontsize:28;fontname:Arial" attrname="Name" x="624" y="2144" type="branch" />
            <wire x2="624" y1="2064" y2="2144" x1="624" />
        </branch>
        <branch name="V0">
            <attrtext style="alignment:SOFT-VLEFT;fontsize:28;fontname:Arial" attrname="Name" x="864" y="2000" type="branch" />
            <wire x2="864" y1="2000" y2="2096" x1="864" />
        </branch>
        <instance x="560" y="2064" name="XLXI_8" orien="R0" />
        <instance x="800" y="2224" name="XLXI_9" orien="R0" />
        <branch name="V5,V5,V5,V0">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1936" type="branch" />
            <wire x2="1552" y1="1936" y2="1936" x1="1328" />
        </branch>
        <branch name="V5,V0,V5,V5">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="2000" type="branch" />
            <wire x2="1552" y1="2000" y2="2000" x1="1328" />
        </branch>
        <branch name="V0,V5,V5,V5">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="2064" type="branch" />
            <wire x2="1552" y1="2064" y2="2064" x1="1328" />
        </branch>
        <branch name="V5,V5,V0,V5">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="2128" type="branch" />
            <wire x2="1552" y1="2128" y2="2128" x1="1328" />
        </branch>
        <branch name="AN(3:0)">
            <wire x2="1968" y1="1872" y2="1872" x1="1936" />
        </branch>
        <iomarker fontsize="28" x="1968" y="1872" name="AN(3:0)" orien="R0" />
        <branch name="o(3:0)">
            <wire x2="2112" y1="544" y2="544" x1="1936" />
            <wire x2="2112" y1="544" y2="1024" x1="2112" />
            <wire x2="2112" y1="1024" y2="1040" x1="2112" />
            <wire x2="2112" y1="1040" y2="1120" x1="2112" />
            <wire x2="2112" y1="1120" y2="1200" x1="2112" />
            <wire x2="2112" y1="1200" y2="1280" x1="2112" />
            <wire x2="2112" y1="1280" y2="1344" x1="2112" />
        </branch>
        <bustap x2="2208" y1="1040" y2="1040" x1="2112" />
        <branch name="o(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2352" y="1040" type="branch" />
            <wire x2="2352" y1="1040" y2="1040" x1="2208" />
            <wire x2="2496" y1="1040" y2="1040" x1="2352" />
        </branch>
        <bustap x2="2208" y1="1120" y2="1120" x1="2112" />
        <branch name="o(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2352" y="1120" type="branch" />
            <wire x2="2352" y1="1120" y2="1120" x1="2208" />
            <wire x2="2496" y1="1120" y2="1120" x1="2352" />
        </branch>
        <bustap x2="2208" y1="1200" y2="1200" x1="2112" />
        <branch name="o(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2352" y="1200" type="branch" />
            <wire x2="2352" y1="1200" y2="1200" x1="2208" />
            <wire x2="2496" y1="1200" y2="1200" x1="2352" />
        </branch>
        <bustap x2="2208" y1="1280" y2="1280" x1="2112" />
        <branch name="o(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2352" y="1280" type="branch" />
            <wire x2="2352" y1="1280" y2="1280" x1="2208" />
            <wire x2="2496" y1="1280" y2="1280" x1="2352" />
        </branch>
        <branch name="XLXN_45">
            <wire x2="2224" y1="1440" y2="1440" x1="1936" />
            <wire x2="2224" y1="880" y2="1440" x1="2224" />
            <wire x2="2496" y1="880" y2="880" x1="2224" />
        </branch>
        <instance x="1552" y="832" name="XLXI_3" orien="R0">
        </instance>
        <instance x="2496" y="1360" name="XLXI_4" orien="R0">
        </instance>
        <branch name="XLXN_46">
            <wire x2="1952" y1="1008" y2="1008" x1="1936" />
            <wire x2="2480" y1="960" y2="960" x1="1952" />
            <wire x2="2496" y1="960" y2="960" x1="2480" />
            <wire x2="1952" y1="960" y2="1008" x1="1952" />
        </branch>
        <iomarker fontsize="28" x="864" y="960" name="SW(7:0)" orien="R270" />
        <branch name="SW(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1264" type="branch" />
            <wire x2="1248" y1="1264" y2="1264" x1="960" />
            <wire x2="1256" y1="1264" y2="1264" x1="1248" />
            <wire x2="1552" y1="1264" y2="1264" x1="1256" />
        </branch>
        <branch name="SW(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1200" type="branch" />
            <wire x2="1248" y1="1200" y2="1200" x1="960" />
            <wire x2="1256" y1="1200" y2="1200" x1="1248" />
            <wire x2="1552" y1="1200" y2="1200" x1="1256" />
        </branch>
        <branch name="SW(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1136" type="branch" />
            <wire x2="1248" y1="1136" y2="1136" x1="960" />
            <wire x2="1256" y1="1136" y2="1136" x1="1248" />
            <wire x2="1552" y1="1136" y2="1136" x1="1256" />
        </branch>
        <branch name="SW(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1256" y="1072" type="branch" />
            <wire x2="1248" y1="1072" y2="1072" x1="960" />
            <wire x2="1256" y1="1072" y2="1072" x1="1248" />
            <wire x2="1552" y1="1072" y2="1072" x1="1256" />
        </branch>
        <instance x="1552" y="1296" name="XLXI_5" orien="R0">
        </instance>
        <branch name="SEGMENT(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3136" y="1164" type="branch" />
            <wire x2="3136" y1="784" y2="880" x1="3136" />
            <wire x2="3136" y1="880" y2="944" x1="3136" />
            <wire x2="3136" y1="944" y2="1008" x1="3136" />
            <wire x2="3136" y1="1008" y2="1072" x1="3136" />
            <wire x2="3136" y1="1072" y2="1136" x1="3136" />
            <wire x2="3136" y1="1136" y2="1164" x1="3136" />
            <wire x2="3136" y1="1164" y2="1200" x1="3136" />
            <wire x2="3136" y1="1200" y2="1264" x1="3136" />
            <wire x2="3136" y1="1264" y2="1328" x1="3136" />
            <wire x2="3136" y1="1328" y2="1440" x1="3136" />
        </branch>
        <iomarker fontsize="28" x="3136" y="784" name="SEGMENT(7:0)" orien="R270" />
        <bustap x2="3040" y1="880" y2="880" x1="3136" />
        <branch name="SEGMENT(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="880" type="branch" />
            <wire x2="2960" y1="880" y2="880" x1="2880" />
            <wire x2="3040" y1="880" y2="880" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1328" y2="1328" x1="3136" />
        <branch name="SEGMENT(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1328" type="branch" />
            <wire x2="2960" y1="1328" y2="1328" x1="2880" />
            <wire x2="3040" y1="1328" y2="1328" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1264" y2="1264" x1="3136" />
        <branch name="SEGMENT(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1264" type="branch" />
            <wire x2="2960" y1="1264" y2="1264" x1="2880" />
            <wire x2="3040" y1="1264" y2="1264" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1200" y2="1200" x1="3136" />
        <branch name="SEGMENT(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1200" type="branch" />
            <wire x2="2960" y1="1200" y2="1200" x1="2880" />
            <wire x2="3040" y1="1200" y2="1200" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1136" y2="1136" x1="3136" />
        <branch name="SEGMENT(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1136" type="branch" />
            <wire x2="2960" y1="1136" y2="1136" x1="2880" />
            <wire x2="3040" y1="1136" y2="1136" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1072" y2="1072" x1="3136" />
        <branch name="SEGMENT(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1072" type="branch" />
            <wire x2="2960" y1="1072" y2="1072" x1="2880" />
            <wire x2="3040" y1="1072" y2="1072" x1="2960" />
        </branch>
        <bustap x2="3040" y1="1008" y2="1008" x1="3136" />
        <branch name="SEGMENT(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="1008" type="branch" />
            <wire x2="2960" y1="1008" y2="1008" x1="2880" />
            <wire x2="3040" y1="1008" y2="1008" x1="2960" />
        </branch>
        <bustap x2="3040" y1="944" y2="944" x1="3136" />
        <branch name="SEGMENT(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2960" y="944" type="branch" />
            <wire x2="2960" y1="944" y2="944" x1="2880" />
            <wire x2="3040" y1="944" y2="944" x1="2960" />
        </branch>
        <instance x="2608" y="2112" name="XLXI_10" orien="R0" />
        <branch name="BN">
            <wire x2="2608" y1="2080" y2="2080" x1="2576" />
        </branch>
        <iomarker fontsize="28" x="2576" y="2080" name="BN" orien="R180" />
        <branch name="K_ROW">
            <wire x2="2864" y1="2080" y2="2080" x1="2832" />
        </branch>
        <iomarker fontsize="28" x="2864" y="2080" name="K_ROW" orien="R0" />
    </sheet>
</drawing>