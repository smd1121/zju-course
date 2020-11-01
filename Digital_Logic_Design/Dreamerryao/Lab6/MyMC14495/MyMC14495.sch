<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="point" />
        <signal name="p" />
        <signal name="LE" />
        <signal name="a" />
        <signal name="b" />
        <signal name="c" />
        <signal name="d" />
        <signal name="e" />
        <signal name="f" />
        <signal name="g" />
        <signal name="XLXN_13" />
        <signal name="D3" />
        <signal name="D2" />
        <signal name="D1" />
        <signal name="D0" />
        <signal name="ND3" />
        <signal name="ND2" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="ND1" />
        <signal name="ND0" />
        <signal name="XLXN_29" />
        <signal name="XLXN_35" />
        <signal name="XLXN_31" />
        <signal name="XLXN_41" />
        <signal name="XLXN_43" />
        <signal name="XLXN_46" />
        <signal name="XLXN_48" />
        <signal name="XLXN_49" />
        <signal name="XLXN_50" />
        <signal name="XLXN_51" />
        <signal name="XLXN_52" />
        <signal name="XLXN_53" />
        <signal name="XLXN_54" />
        <signal name="XLXN_55" />
        <signal name="XLXN_56" />
        <signal name="XLXN_57" />
        <signal name="XLXN_58" />
        <signal name="XLXN_59" />
        <signal name="XLXN_60" />
        <signal name="XLXN_61" />
        <signal name="XLXN_62" />
        <signal name="XLXN_63" />
        <signal name="XLXN_64" />
        <signal name="XLXN_65" />
        <signal name="XLXN_66" />
        <signal name="XLXN_67" />
        <signal name="XLXN_68" />
        <signal name="XLXN_69" />
        <signal name="XLXN_71" />
        <signal name="XLXN_72" />
        <signal name="XLXN_74" />
        <signal name="XLXN_75" />
        <signal name="XLXN_76" />
        <signal name="XLXN_79" />
        <signal name="XLXN_80" />
        <signal name="XLXN_85" />
        <signal name="XLXN_90" />
        <signal name="XLXN_95" />
        <signal name="XLXN_96" />
        <signal name="XLXN_97" />
        <signal name="XLXN_100" />
        <signal name="XLXN_102" />
        <signal name="XLXN_106" />
        <port polarity="Input" name="point" />
        <port polarity="Output" name="p" />
        <port polarity="Input" name="LE" />
        <port polarity="Output" name="a" />
        <port polarity="Output" name="b" />
        <port polarity="Output" name="c" />
        <port polarity="Output" name="d" />
        <port polarity="Output" name="e" />
        <port polarity="Output" name="f" />
        <port polarity="Output" name="g" />
        <port polarity="Input" name="D3" />
        <port polarity="Input" name="D2" />
        <port polarity="Input" name="D1" />
        <port polarity="Input" name="D0" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
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
        <blockdef name="and4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-112" y2="-112" x1="144" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-64" y2="-64" x1="0" />
        </blockdef>
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
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
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="point" name="I" />
            <blockpin signalname="p" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="a" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_31" name="I1" />
            <blockpin signalname="b" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_4">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_48" name="I1" />
            <blockpin signalname="c" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_46" name="I1" />
            <blockpin signalname="d" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_6">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_43" name="I1" />
            <blockpin signalname="e" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_7">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_35" name="I1" />
            <blockpin signalname="f" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_8">
            <blockpin signalname="LE" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="g" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_9">
            <blockpin signalname="XLXN_59" name="I0" />
            <blockpin signalname="XLXN_58" name="I1" />
            <blockpin signalname="XLXN_56" name="I2" />
            <blockpin signalname="XLXN_55" name="I3" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_10">
            <blockpin signalname="D3" name="I" />
            <blockpin signalname="ND3" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_11">
            <blockpin signalname="D2" name="I" />
            <blockpin signalname="ND2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_12">
            <blockpin signalname="D1" name="I" />
            <blockpin signalname="ND1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_13">
            <blockpin signalname="D0" name="I" />
            <blockpin signalname="ND0" name="O" />
        </block>
        <block symbolname="and4" name="AD0">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="ND1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="D3" name="I3" />
            <blockpin signalname="XLXN_79" name="O" />
        </block>
        <block symbolname="and4" name="AD1">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="ND3" name="I3" />
            <blockpin signalname="XLXN_106" name="O" />
        </block>
        <block symbolname="and3" name="AD2">
            <blockpin signalname="ND1" name="I0" />
            <blockpin signalname="ND2" name="I1" />
            <blockpin signalname="ND3" name="I2" />
            <blockpin signalname="XLXN_102" name="O" />
        </block>
        <block symbolname="and3" name="AD3">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="ND3" name="I2" />
            <blockpin signalname="XLXN_76" name="O" />
        </block>
        <block symbolname="and3" name="AD4">
            <blockpin signalname="D1" name="I0" />
            <blockpin signalname="ND2" name="I1" />
            <blockpin signalname="ND3" name="I2" />
            <blockpin signalname="XLXN_75" name="O" />
        </block>
        <block symbolname="and3" name="AD5">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND2" name="I1" />
            <blockpin signalname="ND3" name="I2" />
            <blockpin signalname="XLXN_74" name="O" />
        </block>
        <block symbolname="and3" name="AD6">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND1" name="I1" />
            <blockpin signalname="ND2" name="I2" />
            <blockpin signalname="XLXN_72" name="O" />
        </block>
        <block symbolname="and3" name="AD7">
            <blockpin signalname="ND1" name="I0" />
            <blockpin signalname="D2" name="I1" />
            <blockpin signalname="ND3" name="I2" />
            <blockpin signalname="XLXN_71" name="O" />
        </block>
        <block symbolname="and2" name="AD8">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND3" name="I1" />
            <blockpin signalname="XLXN_69" name="O" />
        </block>
        <block symbolname="and4" name="AD9">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="ND2" name="I2" />
            <blockpin signalname="D3" name="I3" />
            <blockpin signalname="XLXN_68" name="O" />
        </block>
        <block symbolname="and3" name="AD10">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="XLXN_67" name="O" />
        </block>
        <block symbolname="and3" name="AD11">
            <blockpin signalname="D1" name="I0" />
            <blockpin signalname="D2" name="I1" />
            <blockpin signalname="D3" name="I2" />
            <blockpin signalname="XLXN_66" name="O" />
        </block>
        <block symbolname="and4" name="AD12">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="ND2" name="I2" />
            <blockpin signalname="ND3" name="I3" />
            <blockpin signalname="XLXN_65" name="O" />
        </block>
        <block symbolname="and3" name="AD13">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="D3" name="I2" />
            <blockpin signalname="XLXN_64" name="O" />
        </block>
        <block symbolname="and3" name="AD14">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="D2" name="I1" />
            <blockpin signalname="D3" name="I2" />
            <blockpin signalname="XLXN_63" name="O" />
        </block>
        <block symbolname="and3" name="AD15">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="XLXN_61" name="O" />
        </block>
        <block symbolname="and4" name="AD16">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="ND3" name="I3" />
            <blockpin signalname="XLXN_60" name="O" />
        </block>
        <block symbolname="and4" name="AD17">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="D1" name="I1" />
            <blockpin signalname="ND2" name="I2" />
            <blockpin signalname="D3" name="I3" />
            <blockpin signalname="XLXN_59" name="O" />
        </block>
        <block symbolname="and4" name="AD18">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="D3" name="I3" />
            <blockpin signalname="XLXN_58" name="O" />
        </block>
        <block symbolname="and4" name="AD19">
            <blockpin signalname="ND0" name="I0" />
            <blockpin signalname="ND1" name="I1" />
            <blockpin signalname="D2" name="I2" />
            <blockpin signalname="ND3" name="I3" />
            <blockpin signalname="XLXN_56" name="O" />
        </block>
        <block symbolname="and4" name="AD20">
            <blockpin signalname="D0" name="I0" />
            <blockpin signalname="ND2" name="I1" />
            <blockpin signalname="ND1" name="I2" />
            <blockpin signalname="ND3" name="I3" />
            <blockpin signalname="XLXN_55" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_35">
            <blockpin signalname="XLXN_64" name="I0" />
            <blockpin signalname="XLXN_63" name="I1" />
            <blockpin signalname="XLXN_61" name="I2" />
            <blockpin signalname="XLXN_60" name="I3" />
            <blockpin signalname="XLXN_31" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_37">
            <blockpin signalname="XLXN_68" name="I0" />
            <blockpin signalname="XLXN_67" name="I1" />
            <blockpin signalname="XLXN_56" name="I2" />
            <blockpin signalname="XLXN_55" name="I3" />
            <blockpin signalname="XLXN_46" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_38">
            <blockpin signalname="XLXN_76" name="I0" />
            <blockpin signalname="XLXN_75" name="I1" />
            <blockpin signalname="XLXN_74" name="I2" />
            <blockpin signalname="XLXN_58" name="I3" />
            <blockpin signalname="XLXN_35" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_39">
            <blockpin signalname="XLXN_79" name="I0" />
            <blockpin signalname="XLXN_106" name="I1" />
            <blockpin signalname="XLXN_102" name="I2" />
            <blockpin signalname="XLXN_41" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_40">
            <blockpin signalname="XLXN_72" name="I0" />
            <blockpin signalname="XLXN_71" name="I1" />
            <blockpin signalname="XLXN_69" name="I2" />
            <blockpin signalname="XLXN_43" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_41">
            <blockpin signalname="XLXN_66" name="I0" />
            <blockpin signalname="XLXN_65" name="I1" />
            <blockpin signalname="XLXN_63" name="I2" />
            <blockpin signalname="XLXN_48" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="5440" height="3520">
        <branch name="point">
            <wire x2="432" y1="464" y2="1280" x1="432" />
        </branch>
        <iomarker fontsize="28" x="432" y="464" name="point" orien="R270" />
        <instance x="400" y="1280" name="XLXI_1" orien="R90" />
        <branch name="p">
            <wire x2="432" y1="1504" y2="3232" x1="432" />
        </branch>
        <iomarker fontsize="28" x="432" y="3232" name="p" orien="R90" />
        <branch name="LE">
            <wire x2="176" y1="416" y2="2928" x1="176" />
            <wire x2="800" y1="2928" y2="2928" x1="176" />
            <wire x2="800" y1="2928" y2="3056" x1="800" />
            <wire x2="1408" y1="2928" y2="2928" x1="800" />
            <wire x2="1408" y1="2928" y2="3088" x1="1408" />
            <wire x2="1920" y1="2928" y2="2928" x1="1408" />
            <wire x2="1920" y1="2928" y2="3072" x1="1920" />
            <wire x2="2512" y1="2928" y2="2928" x1="1920" />
            <wire x2="2512" y1="2928" y2="3088" x1="2512" />
            <wire x2="2880" y1="2928" y2="2928" x1="2512" />
            <wire x2="3472" y1="2928" y2="2928" x1="2880" />
            <wire x2="3472" y1="2928" y2="3072" x1="3472" />
            <wire x2="4512" y1="2928" y2="2928" x1="3472" />
            <wire x2="4512" y1="2928" y2="3040" x1="4512" />
            <wire x2="2880" y1="2928" y2="3072" x1="2880" />
        </branch>
        <iomarker fontsize="28" x="176" y="416" name="LE" orien="R270" />
        <instance x="3408" y="3072" name="XLXI_3" orien="R90" />
        <branch name="a">
            <wire x2="4544" y1="3296" y2="3360" x1="4544" />
        </branch>
        <branch name="b">
            <wire x2="3504" y1="3328" y2="3360" x1="3504" />
        </branch>
        <iomarker fontsize="28" x="3504" y="3360" name="b" orien="R90" />
        <branch name="c">
            <wire x2="2912" y1="3328" y2="3360" x1="2912" />
        </branch>
        <branch name="d">
            <wire x2="2544" y1="3344" y2="3360" x1="2544" />
        </branch>
        <branch name="e">
            <wire x2="1952" y1="3328" y2="3360" x1="1952" />
        </branch>
        <branch name="f">
            <wire x2="1440" y1="3344" y2="3376" x1="1440" />
        </branch>
        <branch name="g">
            <wire x2="832" y1="3312" y2="3344" x1="832" />
        </branch>
        <instance x="4448" y="3040" name="XLXI_2" orien="R90" />
        <iomarker fontsize="28" x="4544" y="3360" name="a" orien="R90" />
        <branch name="XLXN_13">
            <wire x2="4576" y1="2688" y2="3040" x1="4576" />
        </branch>
        <branch name="D3">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4912" y="685" type="branch" />
            <wire x2="720" y1="928" y2="1216" x1="720" />
            <wire x2="2432" y1="928" y2="928" x1="720" />
            <wire x2="2800" y1="928" y2="928" x1="2432" />
            <wire x2="3216" y1="928" y2="928" x1="2800" />
            <wire x2="3424" y1="928" y2="928" x1="3216" />
            <wire x2="4144" y1="928" y2="928" x1="3424" />
            <wire x2="4416" y1="928" y2="928" x1="4144" />
            <wire x2="4912" y1="928" y2="928" x1="4416" />
            <wire x2="4416" y1="928" y2="1216" x1="4416" />
            <wire x2="4144" y1="928" y2="1216" x1="4144" />
            <wire x2="3424" y1="928" y2="1216" x1="3424" />
            <wire x2="3216" y1="928" y2="1216" x1="3216" />
            <wire x2="2800" y1="928" y2="1216" x1="2800" />
            <wire x2="2432" y1="928" y2="1216" x1="2432" />
            <wire x2="5024" y1="416" y2="416" x1="4912" />
            <wire x2="4912" y1="416" y2="685" x1="4912" />
            <wire x2="4912" y1="685" y2="928" x1="4912" />
            <wire x2="5024" y1="224" y2="416" x1="5024" />
        </branch>
        <branch name="D2">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4688" y="590" type="branch" />
            <wire x2="656" y1="832" y2="1216" x1="656" />
            <wire x2="896" y1="832" y2="832" x1="656" />
            <wire x2="896" y1="832" y2="1216" x1="896" />
            <wire x2="1984" y1="832" y2="832" x1="896" />
            <wire x2="1984" y1="832" y2="1216" x1="1984" />
            <wire x2="2608" y1="832" y2="832" x1="1984" />
            <wire x2="2608" y1="832" y2="1216" x1="2608" />
            <wire x2="2736" y1="832" y2="832" x1="2608" />
            <wire x2="2736" y1="832" y2="1216" x1="2736" />
            <wire x2="3360" y1="832" y2="832" x1="2736" />
            <wire x2="3360" y1="832" y2="1216" x1="3360" />
            <wire x2="3616" y1="832" y2="832" x1="3360" />
            <wire x2="3616" y1="832" y2="1216" x1="3616" />
            <wire x2="3808" y1="832" y2="832" x1="3616" />
            <wire x2="3808" y1="832" y2="1216" x1="3808" />
            <wire x2="4352" y1="832" y2="832" x1="3808" />
            <wire x2="4592" y1="832" y2="832" x1="4352" />
            <wire x2="4592" y1="832" y2="1216" x1="4592" />
            <wire x2="4688" y1="832" y2="832" x1="4592" />
            <wire x2="4352" y1="832" y2="1216" x1="4352" />
            <wire x2="4768" y1="400" y2="400" x1="4688" />
            <wire x2="4768" y1="400" y2="416" x1="4768" />
            <wire x2="4688" y1="400" y2="590" x1="4688" />
            <wire x2="4688" y1="590" y2="832" x1="4688" />
            <wire x2="4768" y1="224" y2="400" x1="4768" />
        </branch>
        <iomarker fontsize="28" x="5024" y="224" name="D3" orien="R270" />
        <iomarker fontsize="28" x="4768" y="224" name="D2" orien="R270" />
        <iomarker fontsize="28" x="4560" y="224" name="D1" orien="R270" />
        <branch name="D1">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4448" y="644" type="branch" />
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4560" y="316" type="branch" />
            <wire x2="832" y1="768" y2="1216" x1="832" />
            <wire x2="1264" y1="768" y2="768" x1="832" />
            <wire x2="1376" y1="768" y2="768" x1="1264" />
            <wire x2="2304" y1="768" y2="768" x1="1376" />
            <wire x2="2544" y1="768" y2="768" x1="2304" />
            <wire x2="2672" y1="768" y2="768" x1="2544" />
            <wire x2="2912" y1="768" y2="768" x1="2672" />
            <wire x2="3152" y1="768" y2="768" x1="2912" />
            <wire x2="3552" y1="768" y2="768" x1="3152" />
            <wire x2="4016" y1="768" y2="768" x1="3552" />
            <wire x2="4448" y1="768" y2="768" x1="4016" />
            <wire x2="4016" y1="768" y2="1216" x1="4016" />
            <wire x2="3552" y1="768" y2="1216" x1="3552" />
            <wire x2="3152" y1="768" y2="1216" x1="3152" />
            <wire x2="2912" y1="768" y2="1216" x1="2912" />
            <wire x2="2672" y1="768" y2="1216" x1="2672" />
            <wire x2="2544" y1="768" y2="1216" x1="2544" />
            <wire x2="2304" y1="768" y2="1216" x1="2304" />
            <wire x2="1376" y1="768" y2="1216" x1="1376" />
            <wire x2="1264" y1="768" y2="1216" x1="1264" />
            <wire x2="4560" y1="416" y2="416" x1="4448" />
            <wire x2="4448" y1="416" y2="644" x1="4448" />
            <wire x2="4448" y1="644" y2="768" x1="4448" />
            <wire x2="4560" y1="224" y2="316" x1="4560" />
            <wire x2="4560" y1="316" y2="416" x1="4560" />
        </branch>
        <iomarker fontsize="28" x="4352" y="224" name="D0" orien="R270" />
        <branch name="D0">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4224" y="578" type="branch" />
            <wire x2="768" y1="976" y2="1216" x1="768" />
            <wire x2="1184" y1="976" y2="976" x1="768" />
            <wire x2="1184" y1="976" y2="1056" x1="1184" />
            <wire x2="1200" y1="1056" y2="1056" x1="1184" />
            <wire x2="1200" y1="1056" y2="1216" x1="1200" />
            <wire x2="1552" y1="976" y2="976" x1="1184" />
            <wire x2="1552" y1="976" y2="1216" x1="1552" />
            <wire x2="1744" y1="976" y2="976" x1="1552" />
            <wire x2="1744" y1="976" y2="1216" x1="1744" />
            <wire x2="2112" y1="976" y2="976" x1="1744" />
            <wire x2="2112" y1="976" y2="1216" x1="2112" />
            <wire x2="2480" y1="976" y2="976" x1="2112" />
            <wire x2="2480" y1="976" y2="1216" x1="2480" />
            <wire x2="3088" y1="976" y2="976" x1="2480" />
            <wire x2="3088" y1="976" y2="1216" x1="3088" />
            <wire x2="3680" y1="976" y2="976" x1="3088" />
            <wire x2="3680" y1="976" y2="1216" x1="3680" />
            <wire x2="3952" y1="976" y2="976" x1="3680" />
            <wire x2="4224" y1="976" y2="976" x1="3952" />
            <wire x2="4224" y1="976" y2="1216" x1="4224" />
            <wire x2="4720" y1="976" y2="976" x1="4224" />
            <wire x2="4720" y1="976" y2="1216" x1="4720" />
            <wire x2="3952" y1="976" y2="1216" x1="3952" />
            <wire x2="4224" y1="352" y2="578" x1="4224" />
            <wire x2="4224" y1="578" y2="976" x1="4224" />
            <wire x2="4352" y1="352" y2="352" x1="4224" />
            <wire x2="4352" y1="352" y2="416" x1="4352" />
            <wire x2="4352" y1="224" y2="352" x1="4352" />
        </branch>
        <instance x="4992" y="416" name="XLXI_10" orien="R90" />
        <instance x="4736" y="416" name="XLXI_11" orien="R90" />
        <instance x="4528" y="416" name="XLXI_12" orien="R90" />
        <instance x="4320" y="416" name="XLXI_13" orien="R90" />
        <instance x="464" y="1216" name="AD0" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="704" y="1216" name="AD1" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="944" y="1216" name="AD2" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="1136" y="1216" name="AD3" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="1312" y="1216" name="AD4" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="1488" y="1216" name="AD5" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="1680" y="1216" name="AD6" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="1856" y="1216" name="AD7" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="2048" y="1216" name="AD8" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="2176" y="1216" name="AD9" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="2416" y="1216" name="AD10" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="2608" y="1216" name="AD11" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="2784" y="1216" name="AD12" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="3024" y="1216" name="AD13" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="3232" y="1216" name="AD14" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="3424" y="1216" name="AD15" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="3616" y="1216" name="AD16" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="3888" y="1216" name="AD17" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="4160" y="1216" name="AD18" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="4400" y="1216" name="AD19" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <branch name="ND3">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="5024" y="955" type="branch" />
            <wire x2="960" y1="1072" y2="1216" x1="960" />
            <wire x2="1136" y1="1072" y2="1072" x1="960" />
            <wire x2="1136" y1="1072" y2="1216" x1="1136" />
            <wire x2="1328" y1="1072" y2="1072" x1="1136" />
            <wire x2="1328" y1="1072" y2="1216" x1="1328" />
            <wire x2="1504" y1="1072" y2="1072" x1="1328" />
            <wire x2="1504" y1="1072" y2="1216" x1="1504" />
            <wire x2="1680" y1="1072" y2="1072" x1="1504" />
            <wire x2="1680" y1="1072" y2="1216" x1="1680" />
            <wire x2="2048" y1="1072" y2="1072" x1="1680" />
            <wire x2="2048" y1="1072" y2="1216" x1="2048" />
            <wire x2="2176" y1="1072" y2="1072" x1="2048" />
            <wire x2="2176" y1="1072" y2="1216" x1="2176" />
            <wire x2="3040" y1="1072" y2="1072" x1="2176" />
            <wire x2="3040" y1="1072" y2="1216" x1="3040" />
            <wire x2="3872" y1="1072" y2="1072" x1="3040" />
            <wire x2="3872" y1="1072" y2="1216" x1="3872" />
            <wire x2="4656" y1="1072" y2="1072" x1="3872" />
            <wire x2="5024" y1="1072" y2="1072" x1="4656" />
            <wire x2="5024" y1="1072" y2="1216" x1="5024" />
            <wire x2="4656" y1="1072" y2="1216" x1="4656" />
            <wire x2="5024" y1="1216" y2="1216" x1="4912" />
            <wire x2="5024" y1="640" y2="955" x1="5024" />
            <wire x2="5024" y1="955" y2="1072" x1="5024" />
        </branch>
        <branch name="ND2">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4768" y="779" type="branch" />
            <wire x2="1072" y1="1008" y2="1216" x1="1072" />
            <wire x2="1440" y1="1008" y2="1008" x1="1072" />
            <wire x2="1440" y1="1008" y2="1216" x1="1440" />
            <wire x2="1616" y1="1008" y2="1008" x1="1440" />
            <wire x2="1616" y1="1008" y2="1216" x1="1616" />
            <wire x2="1872" y1="1008" y2="1008" x1="1616" />
            <wire x2="2368" y1="1008" y2="1008" x1="1872" />
            <wire x2="2368" y1="1008" y2="1216" x1="2368" />
            <wire x2="2976" y1="1008" y2="1008" x1="2368" />
            <wire x2="2976" y1="1008" y2="1216" x1="2976" />
            <wire x2="4080" y1="1008" y2="1008" x1="2976" />
            <wire x2="4080" y1="1008" y2="1216" x1="4080" />
            <wire x2="4768" y1="1008" y2="1008" x1="4080" />
            <wire x2="4784" y1="1008" y2="1008" x1="4768" />
            <wire x2="4784" y1="1008" y2="1216" x1="4784" />
            <wire x2="1872" y1="1008" y2="1216" x1="1872" />
            <wire x2="4768" y1="640" y2="779" x1="4768" />
            <wire x2="4768" y1="779" y2="1008" x1="4768" />
        </branch>
        <branch name="ND1">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4560" y="779" type="branch" />
            <wire x2="592" y1="896" y2="1216" x1="592" />
            <wire x2="1008" y1="896" y2="896" x1="592" />
            <wire x2="1008" y1="896" y2="1216" x1="1008" />
            <wire x2="1808" y1="896" y2="896" x1="1008" />
            <wire x2="1808" y1="896" y2="1216" x1="1808" />
            <wire x2="1920" y1="896" y2="896" x1="1808" />
            <wire x2="1920" y1="896" y2="1216" x1="1920" />
            <wire x2="3744" y1="896" y2="896" x1="1920" />
            <wire x2="3744" y1="896" y2="1216" x1="3744" />
            <wire x2="4288" y1="896" y2="896" x1="3744" />
            <wire x2="4288" y1="896" y2="1216" x1="4288" />
            <wire x2="4528" y1="896" y2="896" x1="4288" />
            <wire x2="4560" y1="896" y2="896" x1="4528" />
            <wire x2="4848" y1="896" y2="896" x1="4560" />
            <wire x2="4848" y1="896" y2="1216" x1="4848" />
            <wire x2="4528" y1="896" y2="1216" x1="4528" />
            <wire x2="4560" y1="640" y2="779" x1="4560" />
            <wire x2="4560" y1="779" y2="896" x1="4560" />
        </branch>
        <branch name="ND0">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4320" y="669" type="branch" />
            <wire x2="528" y1="1136" y2="1216" x1="528" />
            <wire x2="2240" y1="1136" y2="1136" x1="528" />
            <wire x2="2240" y1="1136" y2="1216" x1="2240" />
            <wire x2="2848" y1="1136" y2="1136" x1="2240" />
            <wire x2="2848" y1="1136" y2="1216" x1="2848" />
            <wire x2="3296" y1="1136" y2="1136" x1="2848" />
            <wire x2="3296" y1="1136" y2="1216" x1="3296" />
            <wire x2="3488" y1="1136" y2="1136" x1="3296" />
            <wire x2="4320" y1="1136" y2="1136" x1="3488" />
            <wire x2="4464" y1="1136" y2="1136" x1="4320" />
            <wire x2="4464" y1="1136" y2="1216" x1="4464" />
            <wire x2="3488" y1="1136" y2="1216" x1="3488" />
            <wire x2="4352" y1="640" y2="640" x1="4320" />
            <wire x2="4320" y1="640" y2="669" x1="4320" />
            <wire x2="4320" y1="669" y2="1136" x1="4320" />
        </branch>
        <branch name="XLXN_31">
            <wire x2="3520" y1="2688" y2="3056" x1="3520" />
            <wire x2="3536" y1="3056" y2="3056" x1="3520" />
            <wire x2="3536" y1="3056" y2="3072" x1="3536" />
        </branch>
        <instance x="4656" y="1216" name="AD20" orien="R90">
            <attrtext style="alignment:VLEFT;fontsize:28;fontname:Arial" attrname="InstName" x="256" y="-8" type="instance" />
        </instance>
        <instance x="4416" y="2432" name="XLXI_9" orien="R90" />
        <branch name="XLXN_55">
            <wire x2="4816" y1="2320" y2="2320" x1="2672" />
            <wire x2="4816" y1="2320" y2="2432" x1="4816" />
            <wire x2="2672" y1="2320" y2="2416" x1="2672" />
            <wire x2="4816" y1="2432" y2="2432" x1="4672" />
            <wire x2="4816" y1="1472" y2="2320" x1="4816" />
        </branch>
        <branch name="XLXN_56">
            <wire x2="2608" y1="2144" y2="2416" x1="2608" />
            <wire x2="4560" y1="2144" y2="2144" x1="2608" />
            <wire x2="4608" y1="2144" y2="2144" x1="4560" />
            <wire x2="4608" y1="2144" y2="2432" x1="4608" />
            <wire x2="4560" y1="1472" y2="2144" x1="4560" />
        </branch>
        <branch name="XLXN_58">
            <wire x2="1568" y1="2224" y2="2368" x1="1568" />
            <wire x2="4320" y1="2224" y2="2224" x1="1568" />
            <wire x2="4544" y1="2224" y2="2224" x1="4320" />
            <wire x2="4544" y1="2224" y2="2432" x1="4544" />
            <wire x2="4320" y1="1472" y2="2224" x1="4320" />
        </branch>
        <branch name="XLXN_59">
            <wire x2="4048" y1="1472" y2="2432" x1="4048" />
            <wire x2="4480" y1="2432" y2="2432" x1="4048" />
        </branch>
        <branch name="XLXN_60">
            <wire x2="3776" y1="2432" y2="2432" x1="3616" />
            <wire x2="3776" y1="1472" y2="2432" x1="3776" />
        </branch>
        <branch name="XLXN_61">
            <wire x2="3552" y1="1472" y2="2432" x1="3552" />
        </branch>
        <branch name="XLXN_63">
            <wire x2="3008" y1="2080" y2="2400" x1="3008" />
            <wire x2="3360" y1="2080" y2="2080" x1="3008" />
            <wire x2="3488" y1="2080" y2="2080" x1="3360" />
            <wire x2="3488" y1="2080" y2="2432" x1="3488" />
            <wire x2="3360" y1="1472" y2="2080" x1="3360" />
        </branch>
        <branch name="XLXN_64">
            <wire x2="3152" y1="1472" y2="2432" x1="3152" />
            <wire x2="3424" y1="2432" y2="2432" x1="3152" />
        </branch>
        <branch name="XLXN_65">
            <wire x2="2944" y1="1472" y2="2400" x1="2944" />
        </branch>
        <branch name="XLXN_67">
            <wire x2="2544" y1="1472" y2="2416" x1="2544" />
        </branch>
        <branch name="XLXN_69">
            <wire x2="2144" y1="2368" y2="2368" x1="2048" />
            <wire x2="2144" y1="1472" y2="2368" x1="2144" />
        </branch>
        <branch name="XLXN_71">
            <wire x2="1984" y1="1472" y2="2368" x1="1984" />
        </branch>
        <branch name="XLXN_74">
            <wire x2="1616" y1="1488" y2="1488" x1="1504" />
            <wire x2="1504" y1="1488" y2="2368" x1="1504" />
            <wire x2="1616" y1="1472" y2="1488" x1="1616" />
        </branch>
        <branch name="XLXN_75">
            <wire x2="1440" y1="1472" y2="2368" x1="1440" />
        </branch>
        <instance x="736" y="2352" name="XLXI_39" orien="R90" />
        <branch name="XLXN_79">
            <wire x2="624" y1="1472" y2="1488" x1="624" />
            <wire x2="800" y1="1488" y2="1488" x1="624" />
            <wire x2="800" y1="1488" y2="2352" x1="800" />
        </branch>
        <branch name="XLXN_41">
            <wire x2="864" y1="2608" y2="3056" x1="864" />
        </branch>
        <instance x="736" y="3056" name="XLXI_8" orien="R90" />
        <iomarker fontsize="28" x="832" y="3344" name="g" orien="R90" />
        <instance x="1312" y="2368" name="XLXI_38" orien="R90" />
        <branch name="XLXN_76">
            <wire x2="1264" y1="1472" y2="1488" x1="1264" />
            <wire x2="1376" y1="1488" y2="1488" x1="1264" />
            <wire x2="1376" y1="1488" y2="2368" x1="1376" />
        </branch>
        <branch name="XLXN_35">
            <wire x2="1472" y1="2624" y2="3088" x1="1472" />
        </branch>
        <instance x="1344" y="3088" name="XLXI_7" orien="R90" />
        <iomarker fontsize="28" x="1440" y="3376" name="f" orien="R90" />
        <instance x="1856" y="2368" name="XLXI_40" orien="R90" />
        <branch name="XLXN_72">
            <wire x2="1808" y1="1472" y2="1488" x1="1808" />
            <wire x2="1920" y1="1488" y2="1488" x1="1808" />
            <wire x2="1920" y1="1488" y2="2368" x1="1920" />
        </branch>
        <branch name="XLXN_43">
            <wire x2="1984" y1="2624" y2="3072" x1="1984" />
        </branch>
        <instance x="1856" y="3072" name="XLXI_6" orien="R90" />
        <iomarker fontsize="28" x="1952" y="3360" name="e" orien="R90" />
        <instance x="2416" y="2416" name="XLXI_37" orien="R90" />
        <branch name="XLXN_68">
            <wire x2="2336" y1="1472" y2="1488" x1="2336" />
            <wire x2="2480" y1="1488" y2="1488" x1="2336" />
            <wire x2="2480" y1="1488" y2="2416" x1="2480" />
        </branch>
        <branch name="XLXN_46">
            <wire x2="2576" y1="2672" y2="3088" x1="2576" />
        </branch>
        <instance x="2448" y="3088" name="XLXI_5" orien="R90" />
        <iomarker fontsize="28" x="2544" y="3360" name="d" orien="R90" />
        <instance x="2816" y="2400" name="XLXI_41" orien="R90" />
        <branch name="XLXN_66">
            <wire x2="2736" y1="1472" y2="1488" x1="2736" />
            <wire x2="2880" y1="1488" y2="1488" x1="2736" />
            <wire x2="2880" y1="1488" y2="2400" x1="2880" />
        </branch>
        <branch name="XLXN_48">
            <wire x2="2944" y1="2656" y2="3072" x1="2944" />
        </branch>
        <instance x="2816" y="3072" name="XLXI_4" orien="R90" />
        <iomarker fontsize="28" x="2912" y="3360" name="c" orien="R90" />
        <instance x="3360" y="2432" name="XLXI_35" orien="R90" />
        <branch name="XLXN_102">
            <wire x2="1072" y1="2352" y2="2352" x1="928" />
            <wire x2="1072" y1="1472" y2="2352" x1="1072" />
        </branch>
        <branch name="XLXN_106">
            <wire x2="864" y1="1472" y2="2352" x1="864" />
        </branch>
    </sheet>
</drawing>