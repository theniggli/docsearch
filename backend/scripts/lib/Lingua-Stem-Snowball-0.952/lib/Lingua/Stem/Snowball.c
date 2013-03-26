/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of Snowball.xs. Do not edit this file, edit Snowball.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/Lingua/Stem/Snowball.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#define NEED_sv_2pv_flags
#define NEED_sv_2pv_nolen
#include "../ppport.h"

#define NUMLANG 15
#define NUMSTEM 29

#include "include/libstemmer.h"

/* All Lingua::Stem::Snowball objects and all calls to stem(),
 * stem_in_place(), etc, reference the same set of Snowball struct
 * sb_stemmers, all held in the singleton object
 * $Lingua::Stem::Snowball::stemmifier, of class
 * Lingua::Stem::Snowball::Stemmifier.  Each sb_stemmer is created lazily, as
 * soon as there is a need for its unique combination of language and
 * encoding.  They are destroyed during global cleanup, when
 * $Lingua::Stem::Snowball::stemmifier is reclaimed.
 */

typedef struct Stemmifier {
    struct sb_stemmer **stemmers;
} Stemmifier;

typedef struct LangEnc {
    char *lang;
    char *encoding; /* the real name of the encoding */
    char *snowenc;  /* the variant that libstemmer_c needs */
} LangEnc;

LangEnc lang_encs[] = {
    { "da", "ISO-8859-1", "ISO_8859_1" },
    { "de", "ISO-8859-1", "ISO_8859_1" },
    { "nl", "ISO-8859-1", "ISO_8859_1" },
    { "en", "ISO-8859-1", "ISO_8859_1" },
    { "es", "ISO-8859-1", "ISO_8859_1" },
    { "fi", "ISO-8859-1", "ISO_8859_1" },
    { "fr", "ISO-8859-1", "ISO_8859_1" },
    { "hu", "ISO-8859-1", "ISO_8859_1" },
    { "it", "ISO-8859-1", "ISO_8859_1" },
    { "no", "ISO-8859-1", "ISO_8859_1" },
    { "pt", "ISO-8859-1", "ISO_8859_1" },
    { "ro", "ISO-8859-2", "ISO_8859_2" },
    { "ru", "KOI8-R",     "KOI8_R",    },
    { "sv", "ISO-8859-1", "ISO_8859_1" },
    { "tr", "UTF-8",      "UTF_8"      },
    { "da", "UTF-8",      "UTF_8"      },
    { "de", "UTF-8",      "UTF_8"      },
    { "nl", "UTF-8",      "UTF_8"      },
    { "en", "UTF-8",      "UTF_8"      },
    { "es", "UTF-8",      "UTF_8"      },
    { "fi", "UTF-8",      "UTF_8"      },
    { "fr", "UTF-8",      "UTF_8"      },
    { "hu", "UTF-8",      "UTF_8"      },
    { "it", "UTF-8",      "UTF_8"      },
    { "no", "UTF-8",      "UTF_8"      },
    { "pt", "UTF-8",      "UTF_8"      },
    { "ro", "UTF-8",      "UTF_8"      },
    { "ru", "UTF-8",      "UTF_8"      },
    { "sv", "UTF-8",      "UTF_8"      },
};

#line 76 "lib/Lingua/Stem/Snowball.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 128 "lib/Lingua/Stem/Snowball.c"

XS(XS_Lingua__Stem__Snowball__derive_stemmer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball__derive_stemmer)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "self_hash");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	HV *	self_hash;

	if (SvROK(ST(0)) && SvTYPE(SvRV(ST(0)))==SVt_PVHV)
	    self_hash = (HV*)SvRV(ST(0));
	else
	    Perl_croak(aTHX_ "self_hash is not a hash reference");
#line 93 "lib/Lingua/Stem/Snowball.xs"
{
    SV   **sv_ptr;
    char  *lang;
    char  *encoding;
    int    i;
    int    stemmer_id = -1;

    /* Extract lang and encoding member variables. */
    sv_ptr = hv_fetch(self_hash, "lang", 4, 0);
    if (!sv_ptr)
        croak("Couldn't find member variable 'lang'");
    lang = SvPV_nolen(*sv_ptr);
    sv_ptr = hv_fetch(self_hash, "encoding", 8, 0);
    if (!sv_ptr)
        croak("Couldn't find member variable 'encoding'");
    encoding = SvPV_nolen(*sv_ptr);

    /* See if the combo of lang and encoding is supported. */
    for(i = 0; i < NUMSTEM; i++) {
        if (   strcmp(lang,     lang_encs[i].lang)     == 0 
            && strcmp(encoding, lang_encs[i].encoding) == 0 
        ) {
            Stemmifier *stemmifier;
            SV         *stemmifier_sv;

            /* We have a match, so we know the stemmer id now. */
            stemmer_id = i;

            /* Retrieve communal Stemmifier. */
            stemmifier_sv = get_sv("Lingua::Stem::Snowball::stemmifier", TRUE);
            if (   sv_isobject(stemmifier_sv)
                && sv_derived_from(stemmifier_sv, 
                    "Lingua::Stem::Snowball::Stemmifier")
            ) {
                IV tmp = SvIV(SvRV(stemmifier_sv));
                stemmifier = INT2PTR(Stemmifier*, tmp);
            }
            else {
                croak("$L::S::S::stemmifier isn't a Stemmifier");
            }

            /* Construct a stemmer for lang/enc if there isn't one yet. */
            if ( ! stemmifier->stemmers[stemmer_id] ) {
                stemmifier->stemmers[stemmer_id] 
                    = sb_stemmer_new(lang, lang_encs[stemmer_id].snowenc);
                if ( ! stemmifier->stemmers[stemmer_id]  ) {
                    croak("Failed to allocate an sb_stemmer for %s %s", lang,
                        encoding);
                }
            } 

            break;
        }
    }

    /* Set the value of $self->{stemmer_id}. */
    sv_ptr = hv_fetch(self_hash, "stemmer_id", 10, 0);
    if (!sv_ptr)
        croak("Couldn't access $self->{stemmer_id}");
    sv_setiv(*sv_ptr, stemmer_id);
}
#line 211 "lib/Lingua/Stem/Snowball.c"
	PUTBACK;
	return;
    }
}


XS(XS_Lingua__Stem__Snowball__validate_language); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball__validate_language)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "language");
    {
	char *	language = (char *)SvPV_nolen(ST(0));
	bool	RETVAL;
#line 159 "lib/Lingua/Stem/Snowball.xs"
{
    int i;
    RETVAL = FALSE;
    for (i = 0; i < NUMLANG; i++) {
        if ( strcmp(language, lang_encs[i].lang) == 0 ) RETVAL = TRUE;
    }
}
#line 239 "lib/Lingua/Stem/Snowball.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Lingua__Stem__Snowball_stemmers); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball_stemmers)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 171 "lib/Lingua/Stem/Snowball.xs"
{
    int i;
    for (i = 0; i < NUMLANG; i++) {
        XPUSHs( sv_2mortal(
            newSVpvn( lang_encs[i].lang, strlen(lang_encs[i].lang) )
        ));
    }
    XSRETURN(NUMLANG);
}
#line 269 "lib/Lingua/Stem/Snowball.c"
	PUTBACK;
	return;
    }
}


XS(XS_Lingua__Stem__Snowball_stem_in_place); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball_stem_in_place)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "self_hash, words_av");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	HV *	self_hash;
	AV *	words_av;

	if (SvROK(ST(0)) && SvTYPE(SvRV(ST(0)))==SVt_PVHV)
	    self_hash = (HV*)SvRV(ST(0));
	else
	    Perl_croak(aTHX_ "self_hash is not a hash reference");

    if (SvROK(ST(1)) && SvTYPE(SvRV(ST(1)))==SVt_PVAV)
        words_av = (AV*)SvRV(ST(1));
    else
        Perl_croak(aTHX_ "words_av is not an array reference");
#line 186 "lib/Lingua/Stem/Snowball.xs"
{
    IV stemmer_id;
    SV **sv_ptr;
    Stemmifier *stemmifier;
    SV *stemmifier_sv;

    /* Retrieve the stemmifier. */
    stemmifier_sv = get_sv("Lingua::Stem::Snowball::stemmifier", TRUE);
    if (   sv_isobject(stemmifier_sv)
        && sv_derived_from(stemmifier_sv, "Lingua::Stem::Snowball::Stemmifier")
    ) {
        IV tmp = SvIV(SvRV(stemmifier_sv));
        stemmifier = INT2PTR(Stemmifier*, tmp);
    }
    else {
        croak("$Lingua::Stem::Snowball::stemmifier isn't a Stemmifier");
    }

    /* Figure out which sb_stemmer to use. */
    sv_ptr = hv_fetch(self_hash, "stemmer_id", 10, 0);
    if (!sv_ptr)
        croak("Couldn't access stemmer_id");
    stemmer_id = SvIV(*sv_ptr);
    if (   stemmer_id < 0 
        || stemmer_id >= NUMSTEM 
        || stemmifier->stemmers[stemmer_id] == NULL
    ) {
        dSP;
        ENTER;
        SAVETMPS;
        PUSHMARK(SP);
        XPUSHs(ST(0));
        PUTBACK;
        call_method("_derive_stemmer", G_DISCARD);
        FREETMPS;
        LEAVE;

        /* Extract what should now be a valid stemmer_id. */
        sv_ptr = hv_fetch(self_hash, "stemmer_id", 10, 0);
        stemmer_id = SvIV(*sv_ptr);
    }
	if (stemmer_id != -1) {
		struct sb_stemmer *stemmer = stemmifier->stemmers[stemmer_id];
        IV i, max;

		for (i = 0, max = av_len(words_av); i <= max; i++) {
			sv_ptr = av_fetch(words_av, i, 0);
			if (SvOK(*sv_ptr)) {
                STRLEN len;
                sb_symbol *input_text = (sb_symbol*)SvPV(*sv_ptr, len);
                const sb_symbol *stemmed_output 
                    = sb_stemmer_stem(stemmer, input_text, (int)len);
                len = sb_stemmer_length(stemmer);
                sv_setpvn(*sv_ptr, (char*)stemmed_output, len);
            }
		}
	}
}
#line 360 "lib/Lingua/Stem/Snowball.c"
	PUTBACK;
	return;
    }
}


XS(XS_Lingua__Stem__Snowball__Stemmifier_new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball__Stemmifier_new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class_name");
    {
	char*	class_name = (char *)SvPV_nolen(ST(0));
	SV *	RETVAL;
#line 251 "lib/Lingua/Stem/Snowball.xs"
{
    Stemmifier *stemmifier;
    New(0, stemmifier, 1, Stemmifier);
    Newz(0, stemmifier->stemmers, NUMSTEM, struct sb_stemmer*);
    RETVAL = newSV(0);
    sv_setref_pv(RETVAL, class_name, (void*)stemmifier);
}
#line 388 "lib/Lingua/Stem/Snowball.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Lingua__Stem__Snowball__Stemmifier_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Lingua__Stem__Snowball__Stemmifier_DESTROY)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "self_sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	self_sv = ST(0);
#line 264 "lib/Lingua/Stem/Snowball.xs"
{
    int i;
    IV temp = SvIV( SvRV(self_sv) );
    Stemmifier *stemmifier = INT2PTR(Stemmifier*, temp);
    for (i = 0; i < NUMSTEM; i++) {
        if (stemmifier->stemmers[i] != NULL)
            sb_stemmer_delete(stemmifier->stemmers[i]);
    }
    Safefree(stemmifier);
}
#line 421 "lib/Lingua/Stem/Snowball.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Lingua__Stem__Snowball); /* prototype to pass -Wmissing-prototypes */
XS(boot_Lingua__Stem__Snowball)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK ;

        newXS("Lingua::Stem::Snowball::_derive_stemmer", XS_Lingua__Stem__Snowball__derive_stemmer, file);
        newXS("Lingua::Stem::Snowball::_validate_language", XS_Lingua__Stem__Snowball__validate_language, file);
        newXS("Lingua::Stem::Snowball::stemmers", XS_Lingua__Stem__Snowball_stemmers, file);
        newXS("Lingua::Stem::Snowball::stem_in_place", XS_Lingua__Stem__Snowball_stem_in_place, file);
        newXS("Lingua::Stem::Snowball::Stemmifier::new", XS_Lingua__Stem__Snowball__Stemmifier_new, file);
        newXS("Lingua::Stem::Snowball::Stemmifier::DESTROY", XS_Lingua__Stem__Snowball__Stemmifier_DESTROY, file);

    /* Initialisation Section */

#line 71 "lib/Lingua/Stem/Snowball.xs"
{
    SV *sb_stemmer_list_sv   = newSViv(PTR2IV(sb_stemmer_list));
    SV *sb_stemmer_new_sv    = newSViv(PTR2IV(sb_stemmer_new));
    SV *sb_stemmer_delete_sv = newSViv(PTR2IV(sb_stemmer_delete));
    SV *sb_stemmer_stem_sv   = newSViv(PTR2IV(sb_stemmer_stem));
    SV *sb_stemmer_length_sv = newSViv(PTR2IV(sb_stemmer_length));
    hv_store(PL_modglobal, "Lingua::Stem::Snowball::sb_stemmer_list", 39,
        sb_stemmer_list_sv, 0);
    hv_store(PL_modglobal, "Lingua::Stem::Snowball::sb_stemmer_new", 38,
        sb_stemmer_new_sv, 0);
    hv_store(PL_modglobal, "Lingua::Stem::Snowball::sb_stemmer_delete", 41,
        sb_stemmer_delete_sv, 0);
    hv_store(PL_modglobal, "Lingua::Stem::Snowball::sb_stemmer_stem", 39,
        sb_stemmer_stem_sv, 0);
    hv_store(PL_modglobal, "Lingua::Stem::Snowball::sb_stemmer_length", 41,
        sb_stemmer_length_sv, 0);
}

#line 479 "lib/Lingua/Stem/Snowball.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
