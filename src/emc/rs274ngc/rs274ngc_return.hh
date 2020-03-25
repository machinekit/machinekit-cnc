//    Copyright 2004-2010 various authors.
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#ifndef RS274NGC_RETURN_HH
#define RS274NGC_RETURN_HH
#include <nml_intf/interp_return.hh>
#define NCE_A_FILE_IS_ALREADY_OPEN _("A file is already open")
#define NCE_ALL_AXES_MISSING_WITH_G52_OR_G92 \
    _("All axes missing with g52 or g92")
#define NCE_ALL_AXES_MISSING_WITH_MOTION_CODE _("All axes missing with motion code")
#define NCE_ARC_RADIUS_TOO_SMALL_TO_REACH_END_POINT _("Arc radius too small to reach end point")
#define NCE_ARGUMENT_TO_ACOS_OUT_OF_RANGE _("Argument to acos out of range")
#define NCE_ARGUMENT_TO_ASIN_OUT_OF_RANGE _("Argument to asin out of range")
#define NCE_ATTEMPT_TO_DIVIDE_BY_ZERO _("Attempt to divide by zero")
#define NCE_ATTEMPT_TO_RAISE_NEGATIVE_TO_NON_INTEGER_POWER _("Attempt to raise negative to non integer power")
#define NCE_BAD_FORMAT_UNSIGNED_INTEGER _("Bad format unsigned integer")
#define NCE_BAD_NUMBER_FORMAT _("Bad number format")
#define NCE_BUG_BAD_G_CODE_MODAL_GROUP_0 _("Bug bad g code modal group 0")
#define NCE_BUG_CODE_NOT_G0_OR_G1 _("Bug code not g0 or g1")
#define NCE_BUG_CODE_NOT_G17_G18_OR_G19 _("Bug code not g17 g18 or g19")
#define NCE_BUG_CODE_NOT_G20_OR_G21 _("Bug code not g20 or g21")
#define NCE_BUG_CODE_NOT_G28_OR_G30 _("Bug code not g28 or g30")
#define NCE_BUG_CODE_NOT_G2_OR_G3 _("Bug code not g2 or g3")
#define NCE_BUG_CODE_NOT_G4_G10_G28_G30_G52_G53_OR_G92_SERIES \
    _("Bug code not g4 g10 g28 g30 g52 g53 or g92 series")
#define NCE_BUG_CODE_NOT_G61_G61_1_OR_G64 _("Bug code not g61 g61.1 or g64")
#define NCE_BUG_CODE_NOT_G90_OR_G91 _("Bug code not g90 or g91")
#define NCE_BUG_CODE_NOT_G98_OR_G99 _("Bug code not g98 or g99")
#define NCE_BUG_CODE_NOT_IN_G52_G92_SERIES _("Bug code not in g52 or g92 series")
#define NCE_BUG_CODE_NOT_IN_RANGE_G54_TO_G593 _("Bug code not in range g54 to g593")
#define NCE_BUG_CODE_NOT_M0_M1_M2_M30_M60 _("Bug code not m0 m1 m2 m30 m60")
#define NCE_BUG_DISTANCE_MODE_NOT_G90_OR_G91 _("Bug distance mode not g90 or g91")
#define NCE_BUG_FUNCTION_SHOULD_NOT_HAVE_BEEN_CALLED _("Bug function should not have been called")
#define NCE_BUG_IN_TOOL_RADIUS_COMP _("Bug in tool radius comp")
#define NCE_BUG_PLANE_NOT_XY_YZ_OR_XZ _("Bug plane not xy yz or xz")
#define NCE_BUG_SIDE_NOT_RIGHT_OR_LEFT _("Bug side not right or left")
#define NCE_BUG_UNKNOWN_MOTION_CODE _("Bug unknown motion code")
#define NCE_BUG_UNKNOWN_OPERATION _("Bug unknown operation")
#define NCE_CANNOT_CHANGE_AXIS_OFFSETS_WITH_CUTTER_RADIUS_COMP _("Cannot change axis offsets with cutter radius comp")
#define NCE_CANNOT_CREATE_BACKUP_FILE _("Cannot create backup file")
#define NCE_CANNOT_DO_G1_WITH_ZERO_FEED_RATE _("Cannot do g1 with zero feed rate")
#define NCE_CANNOT_DO_ZERO_REPEATS_OF_CYCLE _("Cannot do zero repeats of cycle")
#define NCE_CANNOT_MAKE_ARC_WITH_ZERO_FEED_RATE _("Cannot make arc with zero feed rate")
#define NCE_CANNOT_OPEN_BACKUP_FILE _("Cannot open backup file")
#define NCE_CANNOT_OPEN_VARIABLE_FILE _("Cannot open variable file")
#define NCE_CANNOT_PROBE_WITH_CUTTER_RADIUS_COMP_ON _("Cannot probe with cutter radius comp on")
#define NCE_CANNOT_PROBE_WITH_ZERO_FEED_RATE _("Cannot probe with zero feed rate")
#define NCE_CANNOT_PUT_A_B_IN_CANNED_CYCLE _("Cannot put a b in canned cycle")
#define NCE_CANNOT_PUT_A_C_IN_CANNED_CYCLE _("Cannot put a c in canned cycle")
#define NCE_CANNOT_PUT_AN_A_IN_CANNED_CYCLE _("Cannot put an a in canned cycle")
#define NCE_CANNOT_TURN_CUTTER_RADIUS_COMP_ON_WHEN_ON _("Cannot turn cutter radius comp on when on")
#define NCE_CANNOT_USE_AXIS_VALUES_WITH_G80 _("Cannot use axis values with g80")
#define NCE_CANNOT_USE_AXIS_VALUES_WITHOUT_A_G_CODE_THAT_USES_THEM _("Cannot use axis values without a g code that uses them")
#define NCE_CANNOT_USE_G28_OR_G30_WITH_CUTTER_RADIUS_COMP _("Cannot use g28 or g30 with cutter radius comp")
#define NCE_CANNOT_USE_G53_INCREMENTAL _("Cannot use g53 incremental")
#define NCE_CANNOT_USE_G53_WITH_CUTTER_RADIUS_COMP _("Cannot use g53 with cutter radius comp")
#define NCE_CANNOT_USE_TWO_G_CODES_THAT_BOTH_USE_AXIS_VALUES _("Cannot use two g codes that both use axis values")
#define NCE_COMMAND_TOO_LONG _("Command too long")
#define NCE_CURRENT_POINT_SAME_AS_END_POINT_OF_ARC _("Current point same as end point of arc")
#define NCE_DWELL_TIME_MISSING_WITH_G4 _("Dwell time missing with g4")
#define NCE_DWELL_TIME_P_WORD_MISSING_WITH_G82 _("Dwell time p word missing with g82")
#define NCE_DWELL_TIME_P_WORD_MISSING_WITH_G86 _("Dwell time p word missing with g86")
#define NCE_DWELL_TIME_P_WORD_MISSING_WITH_G88 _("Dwell time p word missing with g88")
#define NCE_DWELL_TIME_P_WORD_MISSING_WITH_G89 _("Dwell time p word missing with g89")
#define NCE_EQUAL_SIGN_MISSING_IN_PARAMETER_SETTING _("Equal sign missing in parameter setting")
#define NCE_F_WORD_MISSING_WITH_INVERSE_TIME_ARC_MOVE _("F word missing with inverse time arc move")
#define NCE_F_WORD_MISSING_WITH_INVERSE_TIME_G1_MOVE _("F word missing with inverse time g1 move")
#define NCE_FILE_ENDED_WITH_NO_PERCENT_SIGN _("File ended with no percent sign")
#define NCE_FILE_ENDED_WITH_NO_PERCENT_SIGN_OR_PROGRAM_END _("File ended with no percent sign or program end")
#define NCE_FILE_NAME_TOO_LONG _("File name too long")
#define NCE_G_CODE_OUT_OF_RANGE _("G code out of range")
#define NCE_I_WORD_GIVEN_FOR_ARC_IN_YZ_PLANE _("I word given for arc in yz plane")
#define NCE_I_WORD_MISSING_WITH_G87 _("I word missing with g87")
#define NCE_J_WORD_GIVEN_FOR_ARC_IN_XZ_PLANE _("J word given for arc in xz plane")
#define NCE_J_WORD_MISSING_WITH_G87 _("J word missing with g87")
#define NCE_K_WORD_GIVEN_FOR_ARC_IN_XY_PLANE _("K word given for arc in xy plane")
#define NCE_K_WORD_MISSING_WITH_G87 _("K word missing with g87")
#define NCE_LEFT_BRACKET_MISSING_AFTER_SLASH_WITH_ATAN _("Left bracket missing after slash with atan")
#define NCE_LEFT_BRACKET_MISSING_AFTER_UNARY_OPERATION_NAME _("Left bracket missing after unary operation name")
#define NCE_M_CODE_GREATER_THAN_199 _("M code greater than 199: M%d")
#define NCE_MIXED_RADIUS_IJK_FORMAT_FOR_ARC _("Mixed radius ijk format for arc")
#define NCE_MULTIPLE_A_WORDS_ON_ONE_LINE _("Multiple a words on one line")
#define NCE_MULTIPLE_B_WORDS_ON_ONE_LINE _("Multiple b words on one line")
#define NCE_MULTIPLE_C_WORDS_ON_ONE_LINE _("Multiple c words on one line")
#define NCE_MULTIPLE_D_WORDS_ON_ONE_LINE _("Multiple d words on one line")
#define NCE_MULTIPLE_F_WORDS_ON_ONE_LINE _("Multiple f words on one line")
#define NCE_MULTIPLE_H_WORDS_ON_ONE_LINE _("Multiple h words on one line")
#define NCE_MULTIPLE_I_WORDS_ON_ONE_LINE _("Multiple i words on one line")
#define NCE_MULTIPLE_J_WORDS_ON_ONE_LINE _("Multiple j words on one line")
#define NCE_MULTIPLE_K_WORDS_ON_ONE_LINE _("Multiple k words on one line")
#define NCE_MULTIPLE_L_WORDS_ON_ONE_LINE _("Multiple l words on one line")
#define NCE_MULTIPLE_P_WORDS_ON_ONE_LINE _("Multiple p words on one line")
#define NCE_MULTIPLE_Q_WORDS_ON_ONE_LINE _("Multiple q words on one line")
#define NCE_MULTIPLE_R_WORDS_ON_ONE_LINE _("Multiple r words on one line")
#define NCE_MULTIPLE_S_WORDS_ON_ONE_LINE _("Multiple s words on one line")
#define NCE_MULTIPLE_T_WORDS_ON_ONE_LINE _("Multiple t words on one line")
#define NCE_MULTIPLE_X_WORDS_ON_ONE_LINE _("Multiple x words on one line")
#define NCE_MULTIPLE_Y_WORDS_ON_ONE_LINE _("Multiple y words on one line")
#define NCE_MULTIPLE_Z_WORDS_ON_ONE_LINE _("Multiple z words on one line")
#define NCE_MUST_USE_G0_OR_G1_WITH_G53 _("Must use g0 or g1 with g53")
#define NCE_NEGATIVE_ARGUMENT_TO_SQRT _("Negative argument to sqrt")
#define NCE_NEGATIVE_D_WORD_TOOL_RADIUS_INDEX_USED _("Negative d word tool radius index used")
#define NCE_NEGATIVE_F_WORD_USED _("Negative f word used")
#define NCE_NEGATIVE_G_CODE_USED _("Negative g code used")
#define NCE_NEGATIVE_H_WORD_USED _("Negative h word used")
#define NCE_NEGATIVE_L_WORD_USED _("Negative l word used")
#define NCE_NEGATIVE_M_CODE_USED _("Negative m code used")
#define NCE_NEGATIVE_OR_ZERO_Q_VALUE_USED _("Negative or zero q value used")
#define NCE_NEGATIVE_P_WORD_USED _("Negative p word used")
#define NCE_NEGATIVE_SPINDLE_SPEED_USED _("Negative spindle speed used")
#define NCE_NEGATIVE_TOOL_ID_USED _("Negative tool id used")
#define NCE_NESTED_COMMENT_FOUND _("Nested comment found")
#define NCE_NO_CHARACTERS_FOUND_IN_READING_REAL_VALUE _("No characters found in reading real value")
#define NCE_NON_INTEGER_VALUE_FOR_INTEGER _("Non integer value for integer")
#define NCE_NULL_MISSING_AFTER_NEWLINE _("Null missing after newline")
#define NCE_PARAMETER_FILE_OUT_OF_ORDER _("Parameter file out of order")
#define NCE_PARAMETER_NUMBER_OUT_OF_RANGE _("Parameter number out of range")
#define NCE_PARAMETER_NUMBER_READONLY _("Parameter is readonly")
#define NCE_Q_WORD_MISSING_WITH_G83 _("Q word missing with g83")
#define NCE_QUEUE_IS_NOT_EMPTY_AFTER_PROBING _("Queue is not empty after probing")
#define NCE_R_CLEARANCE_PLANE_UNSPECIFIED_IN_CYCLE _("R clearance plane unspecified in cycle")
#define NCE_R_I_J_K_WORDS_ALL_MISSING_FOR_ARC _("R i j k words all missing for arc")
#define NCE_R_LESS_THAN_X_IN_CYCLE_IN_YZ_PLANE _("R less than x in cycle in yz plane")
#define NCE_R_LESS_THAN_Y_IN_CYCLE_IN_XZ_PLANE _("R less than y in cycle in xz plane")
#define NCE_R_LESS_THAN_Z_IN_CYCLE_IN_XY_PLANE _("R less than z in cycle in xy plane")
#define NCE_R_WORD_WITH_NO_G_CODE_THAT_USES_IT _("R word with no g code that uses it")
#define NCE_SLASH_MISSING_AFTER_FIRST_ATAN_ARGUMENT _("Slash missing after first atan argument")
#define NCE_SPINDLE_NOT_TURNING_CLOCKWISE_IN_G84 _("Spindle not turning clockwise in g84")
#define NCE_SPINDLE_NOT_TURNING_IN_G86 _("Spindle not turning in g86")
#define NCE_SPINDLE_NOT_TURNING_IN_G87 _("Spindle not turning in g87")
#define NCE_SPINDLE_NOT_TURNING_IN_G88 _("Spindle not turning in g88")
#define NCE_SSCANF_FAILED _("Sscanf failed")
#define NCE_START_POINT_TOO_CLOSE_TO_PROBE_POINT _("Start point too close to probe point")
#define NCE_TOO_MANY_M_CODES_ON_LINE _("Too many m codes on line")
#define NCE_POCKET_MAX_TOO_LARGE _("Pocket max too large")
#define NCE_TOOL_RADIUS_NOT_LESS_THAN_ARC_RADIUS_WITH_COMP _("Tool radius not less than arc radius with comp")
#define NCE_TWO_G_CODES_USED_FROM_SAME_MODAL_GROUP _("Two g codes used from same modal group")
#define NCE_TWO_M_CODES_USED_FROM_SAME_MODAL_GROUP _("Two m codes used from same modal group")
#define NCE_UNABLE_TO_OPEN_FILE _("Unable to open file <%s>")
#define NCE_UNCLOSED_COMMENT_FOUND _("Unclosed comment found")
#define NCE_UNCLOSED_EXPRESSION _("Unclosed expression")
#define NCE_UNKNOWN_G_CODE_USED _("Unknown g code used")
#define NCE_UNKNOWN_M_CODE_USED _("Unknown m code used: M%d")
#define NCE_UNKNOWN_OPERATION _("Unknown operation")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_A _("Unknown operation name starting with a")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_M _("Unknown operation name starting with m")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_O _("Unknown operation name starting with o")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_X _("Unknown operation name starting with x")
#define NCE_UNKNOWN_WORD_STARTING_WITH_A _("Unknown word starting with a")
#define NCE_UNKNOWN_WORD_STARTING_WITH_C _("Unknown word starting with c")
#define NCE_UNKNOWN_WORD_STARTING_WITH_E _("Unknown word starting with e")
#define NCE_UNKNOWN_WORD_STARTING_WITH_F _("Unknown word starting with f")
#define NCE_UNKNOWN_WORD_STARTING_WITH_L _("Unknown word starting with l")
#define NCE_UNKNOWN_WORD_STARTING_WITH_R _("Unknown word starting with r")
#define NCE_UNKNOWN_WORD_STARTING_WITH_S _("Unknown word starting with s")
#define NCE_UNKNOWN_WORD_STARTING_WITH_T _("Unknown word starting with t")
#define NCE_UNKNOWN_WORD_WHERE_UNARY_OPERATION_COULD_BE _("Unknown word where unary operation could be")
#define NCE_X_AND_Y_WORDS_MISSING_FOR_ARC_IN_XY_PLANE _("X and y words missing for arc in xy plane")
#define NCE_X_AND_Z_WORDS_MISSING_FOR_ARC_IN_XZ_PLANE _("X and z words missing for arc in xz plane")
#define NCE_X_VALUE_UNSPECIFIED_IN_YZ_PLANE_CANNED_CYCLE _("X value unspecified in yz plane canned cycle")
#define NCE_Y_AND_Z_WORDS_MISSING_FOR_ARC_IN_YZ_PLANE _("Y and z words missing for arc in yz plane")
#define NCE_Y_VALUE_UNSPECIFIED_IN_XZ_PLANE_CANNED_CYCLE _("Y value unspecified in xz plane canned cycle")
#define NCE_Z_VALUE_UNSPECIFIED_IN_XY_PLANE_CANNED_CYCLE _("Z value unspecified in xy plane canned cycle")
#define NCE_ZERO_OR_NEGATIVE_ARGUMENT_TO_LN _("Zero or negative argument to ln")
#define NCE_ZERO_RADIUS_ARC _("Zero radius arc")
#define NCE_K_WORD_MISSING_WITH_G33 _("K word missing with g33/g33.1")
#define NCE_F_WORD_USED_WITH_G33 _("F word used with a g33/g33.1")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_E _("Unknown operation name starting with e")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_N _("Unknown operation name starting with n")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_G _("Unknown operation name starting with g")
#define NCE_UNKNOWN_OPERATION_NAME_STARTING_WITH_L _("Unknown operation name starting with l")
#define NCE_TOO_MANY_SUBROUTINE_PARAMETERS _("Too many subroutine parameters")
#define NCE_TOO_MANY_SUBROUTINE_LEVELS _("Too many subroutine levels")
#define NCE_CALL_STACK_UNDERRUN  _("Bug: call stack underrun")
#define NCE_UNKNOWN_COMMAND_IN_O_LINE _("Unknown control command in o word")
#define NCE_TOO_MANY_OWORD_LABELS _("Too many oword labels")
#define NCE_UNKNOWN_OWORD_NUMBER _("Unknown oword number")
#define NCE_NESTED_SUBROUTINE_DEFN _("Nested subroutine definition")
#define NCE_NOT_IN_SUBROUTINE_DEFN _("Not in subroutine definition")
#define NCE_FILE_NOT_OPEN _("File not open")
#define NCE_CANNOT_REOPEN_FILE _("cannot reopen file %s - removed or renamed? (%s)")
#define NCE_TXX_MISSING_FOR_M6 _("Need tool prepared -Txx- for toolchange")
#define NCE_CANNOT_CHANGE_PLANES_WITH_CUTTER_RADIUS_COMP_ON _("Cannot change planes with cutter radius compensation on")
#define NCE_RADIUS_COMP_ONLY_IN_XY_OR_XZ _("Cutter radius compensation allowed only in XY, XZ planes")
#define NCE_P_WORD_MISSING_WITH_G76 _("P word missing with G76")
#define NCE_I_J_OR_K_WORDS_MISSING_WITH_G76 _("I J or K words missing with G76")
#define NCE_CANNOT_MOVE_ROTARY_AXES_WITH_G76 _("Cannot move rotary axes with G76")
#define NCE_MULTIPLE_E_WORDS_ON_ONE_LINE _("Multiple e words on one line")
#define NCE_NAMED_PARAMETER_NOT_TERMINATED _("Named parameter not terminated")
#define NCE_OUT_OF_MEMORY _("Out of memory")
#define NCE_S_WORD_MISSING_WITH_G96 _("S word missing with G96")
#define NCE_QUEUE_IS_NOT_EMPTY_AFTER_INPUT _("Queue is not empty after external input")
#define NCE_ANALOG_INPUT_WITH_WAIT_NOT_IMMEDIATE _("Can't select analog input with wait type != immediate return")
#define NCE_ZERO_TIMEOUT_WITH_WAIT_NOT_IMMEDIATE _("Zero timeout with wait type != immediate return")
#define NCE_BOTH_DIGITAL_AND_ANALOG_INPUT_SELECTED _("Invalid to select both a digital and an analog input with M66")
#define NCE_INVALID_OR_MISSING_P_AND_E_WORDS_FOR_WAIT_INPUT _("Need to have either a valid P or a valid E word with M66")
#define NCE_Q_WORD_MISSING_WITH_G73 _("Q word missing with g73")
#define NCE_DIGITAL_INPUT_INVALID_ON_M66 _("Digital input selected out of bounds")
#define NCE_ANALOG_INPUT_INVALID_ON_M66 _("Analog input selected out of bounds")
#define NCE_W_VALUE_UNSPECIFIED_IN_UV_PLANE_CANNED_CYCLE _("W value unspecified in UV plane canned cycle")
#define NCE_U_VALUE_UNSPECIFIED_IN_VW_PLANE_CANNED_CYCLE _("U value unspecified in VW plane canned cycle")
#define NCE_V_VALUE_UNSPECIFIED_IN_UW_PLANE_CANNED_CYCLE _("V value unspecified in UW plane canned cycle")
#define NCE_R_LESS_THAN_W_IN_CYCLE_IN_UV_PLANE _("R less than W in cycle in UV plane")
#define NCE_R_LESS_THAN_U_IN_CYCLE_IN_VW_PLANE _("R less than U in cycle in VW plane")
#define NCE_R_LESS_THAN_V_IN_CYCLE_IN_UW_PLANE _("R less than V in cycle in UW plane")
#endif
