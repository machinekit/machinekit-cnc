
file(GLOB MK_LOCALE_FILES "po/*.po")
gettext_create_translations(mk.mo ALL ${MK_LOCALE_FILES})

file(GLOB GMOCCAPY_LOCALE_FILES "po/gmoccapy/*.po")
gettext_create_translations(gmoccapy.mo ALL ${GMOCCAPY_LOCALE_FILES}) 
