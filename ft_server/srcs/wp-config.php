<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress_user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password_here' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'yxy4.6u!B$]$vlX.ZnGO$F,-.fTm9?z1dv0$2mj0:Zd|(Ox_AESMQ{vg}j->0!yd');
define('SECURE_AUTH_KEY',  '`XwuL:k]YzSo;Cepnp)pV;],$JT#tzfP%1hlDads)!Pf+#O?-?Lg(Kd{+i1%`iE|');
define('LOGGED_IN_KEY',    't);ziR4Q7&!WaN+Vncgk%xyFM4NWsJgSjz]>lZH7[MQZ`eMVD` B|QMQL;wwo-8^');
define('NONCE_KEY',        '+Td>T`dM8s:56955?%=5sj(CB9|sBpE*_XhL)fuatu*ww?L>o}#o2*`EKwz6r#M#');
define('AUTH_SALT',        '|&Xb+WYX?k/jjx 2KN|eyWFiU*DqMUl|Ps|r7<r;nUlZD42iz4GkVgt+c^!mUf>t');
define('SECURE_AUTH_SALT', '>e?Lds0(5/LVsFg -8pK--a?-1A&:pBgir]r[GO$H-fIa)!B-x+$Ka|E U-cfl|[');
define('LOGGED_IN_SALT',   '3iqM6Hr{L5[+SrKmr(RNDi-beT;V[Mlazgm&($ad_o*%YSDT[%vh9tt`f@>1Cx0L');
define('NONCE_SALT',       'ZhPFIv||*<8`,$h-[JWdA:.k61lz^Z`p.I*@96r>%&0bx%6:_E(6,S94mN#exZ-a');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
define('FS_METHOD', 'direct');
