<?php /** @var $icons \Theme\Icons */ ?>

<div id="actions" align="center">

    <div id="logo"></div>

    <form id="frmPassReset" action="" method="post" class="form-action" data-onsubmit="user/passreset">
        <fieldset id="resetdata">
            <legend><?php echo _('Solicitud de Cambio de Clave'); ?></legend>
            <?php if (!$passReset): ?>

                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input id="login" name="login" type="text" required
                           class="mdl-textfield__input mdl-color-text--indigo-400"
                           value="<?php echo \SP\Util\Util::init_var('login'); ?>" maxlength="80" autocomplete="off"
                           autofocus>
                    <label class="mdl-textfield__label"
                           for="login"><?php echo _('Usuario'); ?></label>
                </div>
                <br>
                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input id="email" name="email" type="email" required
                           class="mdl-textfield__input mdl-color-text--indigo-400"
                           value="<?php echo \SP\Util\Util::init_var('email'); ?>" maxlength="80" autocomplete="off">
                    <label class="mdl-textfield__label"
                           for="email"><?php echo _('Email del Usuario'); ?></label>
                </div>
            <?php else: ?>
                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input id="pass" name="pass" type="password" required
                           class="mdl-textfield__input mdl-color-text--indigo-400 passwordfield__input"
                           value="<?php echo \SP\Util\Util::init_var('pass'); ?>" maxlength="255" autocomplete="off">
                    <label class="mdl-textfield__label"
                           for="pass"><?php echo _('Clave'); ?></label>
                </div>
                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                    <input id="passR" name="passR" type="password" required
                           class="mdl-textfield__input mdl-color-text--indigo-400"
                           value="<?php echo \SP\Util\Util::init_var('passR'); ?>" maxlength="255" autocomplete="off">
                    <label class="mdl-textfield__label"
                           for="pass"><?php echo _('Clave (repetir)'); ?></label>
                </div>
                <input type="hidden" name="time" value="<?php echo $time; ?>">
                <input type="hidden" name="hash" value="<?php echo $hash; ?>">
            <?php endif; ?>
            <input type="hidden" name="isAjax" value="1">
            <input type="hidden" name="sk" value="">
        </fieldset>

        <div class="buttons">
            <button id="btnBack" type="button" class="mdl-button mdl-js-button mdl-button--raised mdl-button--accent">
                <i class="material-icons"
                   title="<?php echo _('Volver a iniciar sesión'); ?>"><?php echo $icons->getIconBack()->getIcon(); ?></i>
                <?php echo _('Volver'); ?>
            </button>

            <?php if (!$passReset): ?>
                <button id="btnRequest" class="mdl-button mdl-js-button mdl-button--raised mdl-button--accent">
                    <?php echo _('Solicitar'); ?>
                    <i class="material-icons"
                       title="<?php echo _('Solicitar'); ?>"><?php echo $icons->getIconPlay()->getIcon(); ?></i>
                </button>
            <?php else: ?>
                <button id="btnChange" class="mdl-button mdl-js-button mdl-button--raised mdl-button--accent">
                    <?php echo _('Cambiar'); ?>
                    <i class="material-icons"
                       title="<?php echo _('Cambiar'); ?>"><?php echo $icons->getIconPlay()->getIcon(); ?></i>
                </button>
            <?php endif; ?>
        </div>
    </form>
</div>

<script>
    sysPassApp.sk.set("<?php echo $sk; ?>");

    $('#btnBack').click(function () {
        window.history.back();
    });
</script>