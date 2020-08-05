/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _ACE_TOOLS_COMMON_GLYPH_SET_H_
#define _ACE_TOOLS_COMMON_GLYPH_SET_H_

#include <vector>
#include <map>
#include <cstdint>
#include "bitmap.h"

class tGlyphSet {
public:
	static tGlyphSet fromTtf(
		const std::string &szTtfPath, uint8_t ubSize, const std::string &szCharSet,
		uint8_t ubThreshold
	);

	/**
	 * @brief Creates glyph set based on ProMotion NG's PNG font file.
	 *
	 * @param szPngPath Path to png file saved in PMNG's way of saving fonts.
	 * @param ubStartIdx ASCII index of first glyph in PMNG file.
	 * @return Glyph set filled with characters from file.
	 */
	static tGlyphSet fromPmng(const std::string &szPngPath, uint8_t ubStartIdx = 33);

	static tGlyphSet fromDir(const std::string &szDirPath);

	bool toDir(const std::string &szDirPath);

	void toAceFont(const std::string &szFontPath);

	tChunkyBitmap toPackedBitmap(void);

	bool isOk(void);

private:
	struct tBitmapGlyph {
		uint8_t ubBearing;
		uint8_t ubWidth, ubHeight;
		std::vector<uint8_t> vData;

		void trimHorz(bool isRight);
	};

	std::map<char, tBitmapGlyph> m_mGlyphs;
};

#endif // _ACE_TOOLS_COMMON_GLYPH_SET_H_
