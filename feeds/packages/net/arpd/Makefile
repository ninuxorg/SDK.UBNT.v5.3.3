#
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# $Id: Makefile 9349 2007-10-18 18:46:37Z blogic $

include $(TOPDIR)/rules.mk

PKG_NAME:=arpd
PKG_VERSION:=0.2
PKG_RELEASE:=1

PKG_MD5SUM:=e2911fa9de1b92ef50deda1489ae944d
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://niels.xtdnet.nl/honeyd

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/arpd
  SECTION:=net
  CATEGORY:=Network
  DEPENDS:=+libpcap +libdnet +libevent
  TITLE:=A daemon to fake ARP replies
  URL:=http://niels.xtdnet.nl/honeyd/
endef

define Build/Configure
        (cd $(PKG_BUILD_DIR); touch \
		stamp-h.in \
		config.h.in \
	);
	$(call Build/Configure/Default, \
		--with-libdnet="$(STAGING_DIR)/usr" \
		--with-libevent="$(STAGING_DIR)/usr" \
		--with-libpcap="$(STAGING_DIR)/usr" \
	)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CCOPT="$(TARGET_CFLAGS)" \
		INCLS="-I. -I$(STAGING_DIR)/usr/include -I$(STAGING_DIR)/include" \
		LIBS="-L$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/lib -lpcap -ldnet -levent"
endef

define Package/arpd/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/arpd $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,arpd))
